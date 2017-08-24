#include "Particles/ParticleDragForce.h"

#include "Particles/ParticleLayer.h"

namespace DAVA
{
ParticleDragForce::ParticleDragForce(ParticleLayer* parent)
    : parentLayer(parent)
{
}

ParticleDragForce* ParticleDragForce::Clone()
{
    ParticleDragForce* dst = new ParticleDragForce(parentLayer);
    if (forcePowerLine != nullptr)
    {
        dst->forcePowerLine = forcePowerLine->Clone();
        dst->forcePowerLine->Release();
    }
    dst->isActive = isActive;
    dst->timingType = timingType;
    dst->forceName = forceName;
    dst->shape = shape;
    dst->type = type;
    dst->parentLayer = parentLayer;
    dst->position = position;
    dst->rotation = rotation;
    dst->isInfinityRange = isInfinityRange;
    dst->boxSize = boxSize;
    dst->forcePower = forcePower;
    dst->radius = radius;
    return dst;
}

void ParticleDragForce::GetModifableLines(List<ModifiablePropertyLineBase*>& modifiables)
{
    PropertyLineHelper::AddIfModifiable(forcePowerLine.Get(), modifiables);
}
}