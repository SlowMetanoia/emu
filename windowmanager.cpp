#include "windowmanager.h"

WindowManager::WindowManager(QObject *parent) : QObject(parent)
{

}

WindowManager* WindowManager::windowManager = nullptr;

WindowManager* WindowManager::getInstance(){
    if(WindowManager::windowManager == nullptr)
        WindowManager::windowManager = new WindowManager();
    return WindowManager::windowManager;
}

Form* WindowManager::getNewRegistrForm(){
    return new Form();
}
