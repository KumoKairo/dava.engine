#pragma once

#include "Asset/Asset.h"
#include "Base/BaseTypes.h"
#include "UI/UIControl.h"
#include "Reflection/Reflection.h"
#include "Render/Texture.h"

namespace DAVA
{
class UIScreenTransition : public UIControl
{
    DAVA_VIRTUAL_REFLECTION(UIScreenTransition, UIControl);

public:
    UIScreenTransition();

protected:
    ~UIScreenTransition() override;

public:
    void Update(float32 timeElapsed) override;
    void Draw(const UIGeometricData& geometricData) override;

    DAVA_DEPRECATED(virtual void SetSourceScreen(UIControl* prevScreen, bool updateScreen = true));
    DAVA_DEPRECATED(virtual void SetDestinationScreen(UIControl* nextScreen, bool updateScreen = true));
    virtual void SetSourceControl(UIControl* prevScreen, bool updateScreen = true);
    virtual void SetDestinationControl(UIControl* nextScreen, bool updateScreen = true);
    virtual void StartTransition();
    virtual void EndTransition();

    virtual void SetDuration(float32 timeInSeconds);

    bool IsComplete() const;

protected:
    void CreateRenderTargets();
    void ReleaseRenderTargets();
    Sprite* renderTargetPrevScreen = nullptr;
    Asset<Texture> depthTargetPrevScreen;
    Sprite* renderTargetNextScreen = nullptr;
    Asset<Texture> depthTargetNextScreen;

    Interpolation::Func interpolationFunc;
    float32 currentTime = 0.0f;
    float32 duration = 0.7f;
    float32 normalizedTime = 0.0f;
    float32 scale = 1.0f;
    bool complete = false;
};
};
