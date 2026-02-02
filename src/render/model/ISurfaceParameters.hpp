#pragma once

class ISurfaceParameters {
public:
    virtual ~ISurfaceParameters() = default;

    virtual double a() const noexcept = 0;
    virtual double b() const noexcept = 0;
};
