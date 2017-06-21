#pragma once

#include "Physics/PhysicsConfigs.h"

#include <ModuleManager/IModule.h>
#include <ModuleManager/ModuleManager.h>

#include <Math/Vector.h>
#include <Base/BaseTypes.h>

namespace physx
{
class PxFoundation;
class PxPhysics;
class PxCooking;
class PxScene;
class PxActor;
class PxShape;
class PxMaterial;
}

namespace DAVA
{
class PolygonGroup;
class Landscape;
struct Matrix4;

class Physics : public IModule
{
public:
    Physics(Engine* engine);

    void Init() override;
    void Shutdown() override;

    bool IsInitialized() const;
    void* Allocate(size_t size, const char* typeName, const char* filename, int line);
    void Deallocate(void* ptr);

    physx::PxScene* CreateScene(const PhysicsSceneConfig& config) const;

    physx::PxActor* CreateStaticActor() const;
    physx::PxActor* CreateDynamicActor() const;

    physx::PxShape* CreateBoxShape(const Vector3& halfSize) const;
    physx::PxShape* CreateCapsuleShape(float32 radius, float32 halfHeight) const;
    physx::PxShape* CreateSphereShape(float32 radius) const;
    physx::PxShape* CreatePlaneShape() const;
    physx::PxShape* CreateMeshShape(PolygonGroup* polygon, const Vector3& scale) const;
    physx::PxShape* CreateConvexHullShape(PolygonGroup* polygon, const Vector3& scale) const;
    physx::PxShape* CreateHeightField(Landscape* landscape, Matrix4& localPose) const;

    physx::PxMaterial* GetDefaultMaterial() const;

private:
    physx::PxFoundation* foundation = nullptr;
    physx::PxPhysics* physics = nullptr;
    physx::PxCooking* cooking = nullptr;

    mutable physx::PxMaterial* defaultMaterial = nullptr;

    class PhysicsAllocator;
    PhysicsAllocator* allocator = nullptr;

    class PhysicsErrotCallback;
    PhysicsErrotCallback* errorCallback = nullptr;

    DAVA_VIRTUAL_REFLECTION(Physics, IModule);

public:
};
}
