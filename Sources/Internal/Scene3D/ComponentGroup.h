#pragma once

#include "Base/HashVector.h"
#include "Base/Type.h"
#include "Functional/Signal.h"

namespace DAVA
{
class Component;

class ComponentGroupBase
{
public:
    virtual ~ComponentGroupBase() = default;
    ComponentGroupBase() = default;

protected:
    Vector<Component*> cachedAdded;
    Vector<Component*> cachedRemoved;
    const Type* trackedType = nullptr;

    virtual void UpdateCachedAdded() = 0;
    virtual void UpdateCachedRemoved() = 0;
    virtual void EmitAdded(Component* component) = 0;
    virtual void EmitRemoved(Component* component) = 0;
    virtual ComponentGroupBase* Create() = 0;
    virtual void MoveTo(ComponentGroupBase* dest, bool clear = true) = 0;

    friend class EntitiesManager;
};

template <class T>
class ComponentGroup : public ComponentGroupBase
{
public:
    HashVector<T> components;

    std::unique_ptr<Signal<T*>> onComponentAdded;
    std::unique_ptr<Signal<T*>> onComponentRemoved;

private:
    ComponentGroup();
    void UpdateCachedAdded() override;
    void UpdateCachedRemoved() override;
    void EmitAdded(Component* component) override;
    void EmitRemoved(Component* component) override;
    ComponentGroupBase* Create() override;
    void MoveTo(ComponentGroupBase* dest, bool clear = true) override;

    friend class EntitiesManager;
};

template <class T>
class ComponentGroupOnAdd
{
public:
    ComponentGroupOnAdd(ComponentGroup<T>* group);
    ~ComponentGroupOnAdd();

    Vector<T*> components;

private:
    void OnAdded(T* component);
    void OnRemoved(T* component);
    ComponentGroup<T>* group = nullptr;
};
}

#include "Scene3D/Private/ComponentGroup.hpp"
