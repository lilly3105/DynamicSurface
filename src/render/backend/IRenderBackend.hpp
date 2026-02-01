#pragma once

class IRenderBackend
{
public:
  virtual ~IRenderBackend() = default;

  virtual void init() = 0;
  virtual void frame() = 0;
  virtual void shutdown() = 0;

  [[nodiscard]] virtual bool done() const = 0;
};
