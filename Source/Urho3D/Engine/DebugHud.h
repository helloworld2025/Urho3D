// Copyright (c) 2008-2022 the Urho3D project
// License: MIT

#pragma once

#include "../Core/Object.h"
#include "../Core/Timer.h"

namespace Urho3D
{

class Engine;
class Font;
class Text;
class XMLFile;

enum class DebugHudElements
{
    None          = 0,
    Stats         = 1 << 0,
    Mode          = 1 << 1,
    Profiler      = 1 << 2,
    Memory        = 1 << 3,
    EventProfiler = 1 << 4,
    All           = Stats | Mode | Profiler | Memory
};
URHO3D_FLAGS(DebugHudElements);

/// Displays rendering stats and profiling information.
class URHO3D_API DebugHud : public Object
{
    URHO3D_OBJECT(DebugHud, Object);

public:
    /// Construct.
    explicit DebugHud(Context* context);
    /// Destruct.
    ~DebugHud() override;

    /// Update. Called by HandlePostUpdate().
    void Update();
    /// Set UI elements' style from an XML file.
    /// @property
    void SetDefaultStyle(XMLFile* style);

    /// Set elements to show.
    /// @property
    void SetMode(DebugHudElements mode);

    /// Set maximum profiler block depth, default unlimited.
    /// @property
    void SetProfilerMaxDepth(unsigned depth);
    /// Set profiler accumulation interval in seconds.
    /// @property
    void SetProfilerInterval(float interval);
    /// Set whether to show 3D geometry primitive/batch count only. Default false.
    /// @property
    void SetUseRendererStats(bool enable);

    /// Toggle elements.
    void Toggle(DebugHudElements mode);

    /// Toggle all elements.
    void ToggleAll();

    /// Return the UI style file.
    /// @property
    XMLFile* GetDefaultStyle() const;

    /// Return rendering stats text.
    /// @property
    Text* GetStatsText() const { return statsText_; }

    /// Return rendering mode text.
    /// @property
    Text* GetModeText() const { return modeText_; }

    /// Return profiler text.
    /// @property
    Text* GetProfilerText() const { return profilerText_; }

    /// Return memory text.
    /// @property
    Text* GetMemoryText() const { return memoryText_; }

    /// Return currently shown elements.
    /// @property
    DebugHudElements GetMode() const { return mode_; }

    /// Return maximum profiler block depth.
    /// @property
    unsigned GetProfilerMaxDepth() const { return profilerMaxDepth_; }

    /// Return profiler accumulation interval in seconds.
    /// @property
    float GetProfilerInterval() const;

    /// Return whether showing 3D geometry primitive/batch count only.
    /// @property
    bool GetUseRendererStats() const { return useRendererStats_; }

    /// Set application-specific stats.
    void SetAppStats(const String& label, const Variant& stats);
    /// Set application-specific stats.
    void SetAppStats(const String& label, const String& stats);
    /// Reset application-specific stats. Return true if it was erased successfully.
    bool ResetAppStats(const String& label);
    /// Clear all application-specific stats.
    void ClearAppStats();

private:
    /// Handle logic post-update event. The HUD texts are updated here.
    void HandlePostUpdate(StringHash eventType, VariantMap& eventData);

    /// Rendering stats text.
    SharedPtr<Text> statsText_;
    /// Rendering mode text.
    SharedPtr<Text> modeText_;
    /// Profiling information text.
    SharedPtr<Text> profilerText_;
    /// Event profiling information text.
    SharedPtr<Text> eventProfilerText_;
    /// Memory stats text.
    SharedPtr<Text> memoryText_;
    /// Hashmap containing application specific stats.
    HashMap<String, String> appStats_;
    /// Profiler timer.
    Timer profilerTimer_;
    /// Profiler max block depth.
    unsigned profilerMaxDepth_;
    /// Profiler accumulation interval.
    unsigned profilerInterval_;
    /// Show 3D geometry primitive/batch count flag.
    bool useRendererStats_;

    /// Current shown-element mode.
    DebugHudElements mode_;
};

}
