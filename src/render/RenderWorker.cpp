#include "RenderWorker.hpp"

#include "backend/IRenderBackend.hpp"

RenderWorker::RenderWorker(std::unique_ptr<IRenderBackend> backend)
    : backend_(std::move(backend)) {
  backend_->init();
}

RenderWorker::~RenderWorker() = default;

void RenderWorker::run() {
  while (!backend_->done())
    backend_->frame();
  emit quit();
}

void RenderWorker::stop() { backend_->shutdown(); }
