/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PLUGINS_COMPONENT_PLATFORMVIEW_RESOURCE_PLATFORM_VIEW_DELEGATE_H
#define PLUGINS_COMPONENT_PLATFORMVIEW_RESOURCE_PLATFORM_VIEW_DELEGATE_H

#include "platform_view_resource.h"
#include "base/geometry/ng/offset_t.h"
#include "base/geometry/ng/size_t.h"
#include "base/geometry/size.h"
#include "core/common/platform_res_register.h"
#include "core/pipeline/pipeline_base.h"

namespace OHOS::Ace {
class ACE_EXPORT PlatformViewDelegate : public PlatformViewResource {
    DECLARE_ACE_TYPE(PlatformViewDelegate, PlatformViewResource);
public:
    PlatformViewDelegate(const WeakPtr<PipelineBase>& context, ErrorCallback&& onError)
        : PlatformViewResource("platformview", context, std::move(onError)) {}
    ~PlatformViewDelegate() override;

    void Create(const std::string& viewTag);
    void CreatePlatformView(const std::string& viewTag);
    void RegisterPlatformViewTexture(int64_t textureId, std::string& viewTag);
    void UpdatePlatformViewLayout(const NG::SizeF& drawSize, const NG::OffsetF& offset);
    void ExchangeBind();
    void GetPlatformViewType(int32_t& type);
    void HandleTouchDown(const NG::OffsetF& offset);
    void HandleTouchUp(const NG::OffsetF& offset);
    void HandleTouchMove(const NG::OffsetF& offset);
    void HandleTouchCancel(const NG::OffsetF& offset);
    void Dispose();

    void SetPlatformViewReadyCallback(std::function<void()>&& callback)
    {
        onPlatformViewReady_ = std::move(callback);
    }

    std::function<void()> onPlatformViewReady_;
};
} // namespace OHOS::Ace

#endif // PLUGINS_COMPONENT_PLATFORMVIEW_RESOURCE_PLATFORM_VIEW_DELEGATE_H