#include "ServiceLocator.h"

Application* ServiceLocator::_application = nullptr;

void ServiceLocator::SetApplication(Application* application) {
    assert(_application == nullptr);
    _application = application;
}