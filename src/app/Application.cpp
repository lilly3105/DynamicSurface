#include "Application.hpp"
#include "RenderWorker.hpp"
#include "backend/OsgBackend.hpp"
#include "../ui/MainWindow.hpp"

#include <QObject>
#include <qapplication.h>
#include <qnamespace.h>
#include <qthread.h>
#include <QQmlContext>

Application::Application(int argc, char **argv) : app_(argc, argv) {
    initQt();
    initOSG();
}

Application::~Application() {
    renderThread_.quit();
    renderThread_.wait();
}

void Application::initQt() {
    mainWindow_ = std::make_unique<MainWindow>(&viewModel_);
    mainWindow_->show();
}

void Application::initOSG() {
    std::unique_ptr<IRenderBackend> backend = std::make_unique<OsgBackend>(&viewModel_);
    auto *renderWorker = new RenderWorker(std::move(backend));
    renderWorker->moveToThread(&renderThread_);

    QObject::connect(&renderThread_, &QThread::started, renderWorker,
                     &RenderWorker::run);
    QObject::connect(renderWorker, &RenderWorker::quit, &renderThread_,
                     &QThread::quit);
    QObject::connect(renderWorker, &RenderWorker::quit, renderWorker,
                     &RenderWorker::deleteLater);
    QObject::connect(&app_, &QCoreApplication::aboutToQuit, renderWorker,
                     &RenderWorker::stop, Qt::DirectConnection);
    QObject::connect(&renderThread_, &QThread::finished, &app_, &QCoreApplication::quit);

    renderThread_.start();
}

int Application::exec() { return app_.exec(); }
