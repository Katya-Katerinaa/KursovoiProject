/* Copyright (C) 2005-2025, UNIGINE. All rights reserved.
*
* This file is a part of the UNIGINE 2 SDK.
*
* Your use and / or redistribution of this software in source and / or
* binary form, with or without modification, is subject to: (i) your
* ongoing acceptance of and compliance with the terms and conditions of
* the UNIGINE License Agreement; and (ii) your inclusion of this notice
* in any version of this software that you use or redistribute.
* A copy of the UNIGINE License Agreement is available by contacting
* UNIGINE. at http://unigine.com/
*/
// DO NOT EDIT DIRECTLY. This is an auto-generated file. Your changes will be lost.

#pragma once

#include "UnigineBase.h"
#include "UniginePtr.h"
#include "UnigineMathLib.h"
#include "UnigineCallback.h"
#include "UnigineGUID.h"
#include "UnigineCurve2d.h"
#include "UniginePalette.h"
#include "UnigineMeshRender.h"
#include "UnigineTextures.h"

namespace Unigine
{

class BakeLighting;
class Material;
class Object;
class ObjectMeshStatic;
class Viewport;
class Shader;
class RenderTarget;
class Light;
class LightVoxelProbe;
class LightEnvironmentProbe;
class LightPlanarProbe;
class Camera;
class StructuredBuffer;
class Image;
class Node;
class Xml;
class Stream;
class TextureRamp;

class UNIGINE_API RenderEnvironmentPreset : public APIInterface
{
public:
	int getNum() const;
	void setIntensity(float intensity);
	float getIntensity() const;
	void setHazeColor(const Math::vec4 &color);
	Math::vec4 getHazeColor() const;
	void setHazeDensity(float density);
	float getHazeDensity() const;
	void setHazeMaxDistance(float distance);
	float getHazeMaxDistance() const;
	void setHazeScatteringMieIntensity(float intensity);
	float getHazeScatteringMieIntensity() const;
	void setHazeScatteringMieFrontSideIntensity(float intensity);
	float getHazeScatteringMieFrontSideIntensity() const;
	void setHazeScatteringMieFresnelPower(float power);
	float getHazeScatteringMieFresnelPower() const;
	void setHazePhysicalStartHeight(float height);
	float getHazePhysicalStartHeight() const;
	void setHazePhysicalHalfVisibilityDistance(float distance);
	float getHazePhysicalHalfVisibilityDistance() const;
	void setHazePhysicalHalfFalloffHeight(float height);
	float getHazePhysicalHalfFalloffHeight() const;
	void setHazePhysicalAmbientLightIntensity(float intensity);
	float getHazePhysicalAmbientLightIntensity() const;
	void setHazePhysicalAmbientColorSaturation(float saturation);
	float getHazePhysicalAmbientColorSaturation() const;
	void setHazePhysicalSunLightIntensity(float intensity);
	float getHazePhysicalSunLightIntensity() const;
	void setHazePhysicalSunColorSaturation(float saturation);
	float getHazePhysicalSunColorSaturation() const;
	void setScatteringBaseLUTName(const char *name);
	const char *getScatteringBaseLUTName() const;
	void setScatteringMieLUTName(const char *name);
	const char *getScatteringMieLUTName() const;
	void setScatteringLightColorLUTName(const char *name);
	const char *getScatteringLightColorLUTName() const;
	void setSunTextureName(const char *name);
	const char *getSunTextureName() const;
	void setSunAngularSize(float size);
	float getSunAngularSize() const;
	void setSunTextureColor(const Math::vec4 &color);
	Math::vec4 getSunTextureColor() const;
	void setSunTextureIntensity(float intensity);
	float getSunTextureIntensity() const;
	void setMoonTextureName(const char *name);
	const char *getMoonTextureName() const;
	void setMoonAngularSize(float size);
	float getMoonAngularSize() const;
	void setMoonTextureColor(const Math::vec4 &color);
	Math::vec4 getMoonTextureColor() const;
	void setMoonTextureIntensity(float intensity);
	float getMoonTextureIntensity() const;
	void setTextureColor(const Math::vec4 &color);
	Math::vec4 getTextureColor() const;
	void setTextureRotation(const Math::vec3 &rotation);
	Math::vec3 getTextureRotation() const;
	void setTextureBlur(float blur);
	float getTextureBlur() const;
	void setTextureName(const char *name);
	const char *getTextureName() const;
	void setTexture(const Ptr<Texture> &texture);
	Ptr<Texture> getTexture() const;
	void setAmbientIntensity(float intensity);
	float getAmbientIntensity() const;
	void setReflectionIntensity(float intensity);
	float getReflectionIntensity() const;
	void setSkyIntensity(float intensity);
	float getSkyIntensity() const;
};
typedef Ptr<RenderEnvironmentPreset> RenderEnvironmentPresetPtr;

//////////////////////////////////////////////////////////////////////////

class UNIGINE_API Render
{
public:
	static bool isInitialized();

	enum STREAMING_MODE
	{
		STREAMING_MODE_ASYNC,
		STREAMING_MODE_FORCE,
	};

	enum STREAMING_MESHES_PREFETCH
	{
		STREAMING_MESHES_PREFETCH_DISABLE,
		STREAMING_MESHES_PREFETCH_RADIUS,
	};

	enum STREAMING_VRAM_BUDGET
	{
		STREAMING_VRAM_BUDGET_SYSTEM,
		STREAMING_VRAM_BUDGET_DRIVER,
		STREAMING_VRAM_BUDGET_FULL_GPU_MEMORY,
	};

	enum SHADERS_COMPILE_MODE
	{
		SHADERS_COMPILE_MODE_ASYNC,
		SHADERS_COMPILE_MODE_FORCE,
	};

	enum RENDER_API
	{
		API_NULL = 0,
		API_DIRECT3D11,
		API_DIRECT3D12,
		API_VULKAN,
	};

	enum
	{
		QUALITY_LOW = 0,
		QUALITY_MEDIUM,
		QUALITY_HIGH,
	};

	enum CAMERA_MODE
	{
		CAMERA_MODE_CLASSIC,
		CAMERA_MODE_PHYSICALLY_BASED,
	};

	enum EXPOSURE_MODE
	{
		EXPOSURE_MODE_DISABLED = 0,
		EXPOSURE_MODE_LOGARITHMIC,
		EXPOSURE_MODE_QUADRATIC,
		EXPOSURE_MODE_CURVE_BASED,
	};

	enum TONEMAPPER
	{
		TONEMAPPER_FILMIC = 0,
		TONEMAPPER_ACES,
		TONEMAPPER_MIX_ACES_WITH_REINHARD,
		TONEMAPPER_REINHARD,
		TONEMAPPER_REINHARD_LUMA_BASED,
	};

	enum
	{
		TRIANGLES_DISABLED = 0,
		TRIANGLES_FRONT_LEQUAL,
		TRIANGLES_FRONT_ALWAYS,
		TRIANGLES_FRONT_AND_BACK_ALWAYS,
	};

	enum SHOW_IMMOVABLE
	{
		SHOW_IMMOVABLE_DISABLED = 0,
		SHOW_IMMOVABLE_OPTION_ENABLED,
		SHOW_IMMOVABLE_OPTION_DISABLED,
	};

	enum SHOW_LIGHTING_MODE
	{
		SHOW_LIGHTING_MODE_DISABLED = 0,
		SHOW_LIGHTING_MODE_STATIC,
		SHOW_LIGHTING_MODE_DYNAMIC,
		SHOW_LIGHTING_MODE_ADVANCED,
	};

	enum SHOW_VERTEX_COLOR
	{
		SHOW_VERTEX_COLOR_DISABLED = 0,
		SHOW_VERTEX_COLOR_RED,
		SHOW_VERTEX_COLOR_GREEN,
		SHOW_VERTEX_COLOR_BLUE,
		SHOW_VERTEX_COLOR_ALPHA,
		SHOW_VERTEX_COLOR_RGB,
	};

	enum SHOW_TEXTURE_RESOLUTION
	{
		SHOW_TEXTURE_RESOLUTION_DISABLED = 0,
		SHOW_TEXTURE_RESOLUTION_BY_MAX_PIXEL_COUNT,
		SHOW_TEXTURE_RESOLUTION_BY_SCREEN_SIZE,
	};

	enum SHOW_TEXTURE_RESOLUTION_UV
	{
		SHOW_TEXTURE_RESOLUTION_UV_MODE_0,
		SHOW_TEXTURE_RESOLUTION_UV_MODE_1,
	};

	enum SHOW_TEXTURE_RESOLUTION_STREAMING_ACCOUNTING
	{
		SHOW_TEXTURE_RESOLUTION_STREAMING_ACCOUNTING_MODE_ACTUAL,
		SHOW_TEXTURE_RESOLUTION_STREAMING_ACCOUNTING_MODE_REQUESTED,
		SHOW_TEXTURE_RESOLUTION_STREAMING_ACCOUNTING_MODE_SOURCE,
	};

	enum PASS
	{
		PASS_WIREFRAME = 0,
		PASS_VISUALIZER_SOLID,
		PASS_DEFERRED,
		PASS_AUXILIARY,
		PASS_EMISSION,
		PASS_REFRACTION,
		PASS_TRANSPARENT_BLUR,
		PASS_AMBIENT,
		PASS_LIGHT_VOXEL_PROBE,
		PASS_LIGHT_ENVIRONMENT_PROBE,
		PASS_LIGHT_PLANAR_PROBE,
		PASS_LIGHT_OMNI,
		PASS_LIGHT_PROJ,
		PASS_LIGHT_WORLD,
		PASS_SHADOW,
		PASS_DEPTH_PRE_PASS,
		PASS_MS_DEPTH,
		PASS_POST,
		PASS_LIGHTMAP_DATA,
		PASS_PROCEDURAL_DECALS,
		PASS_PROCEDURAL_FIELDS,
		PASS_MIXED_REALITY_BLEND_MASK_COLOR,
		PASS_CUSTOM_0,
		PASS_CUSTOM_1,
		PASS_CUSTOM_2,
		PASS_CUSTOM_3,
		PASS_CUSTOM_4,
		PASS_CUSTOM_5,
		PASS_CUSTOM_6,
		PASS_CUSTOM_7,
		PASS_CUSTOM_8,
		PASS_CUSTOM_9,
		PASS_CUSTOM_10,
		PASS_CUSTOM_11,
		PASS_CUSTOM_12,
		PASS_CUSTOM_13,
		PASS_CUSTOM_14,
		PASS_CUSTOM_15,
		PASS_CUSTOM_16,
		PASS_CUSTOM_17,
		PASS_CUSTOM_18,
		PASS_CUSTOM_19,
		PASS_CUSTOM_20,
		PASS_CUSTOM_21,
		PASS_CUSTOM_22,
		PASS_CUSTOM_23,
		PASS_CUSTOM_24,
		PASS_CUSTOM_25,
		PASS_CUSTOM_26,
		PASS_CUSTOM_27,
		PASS_CUSTOM_28,
		PASS_CUSTOM_29,
		PASS_CUSTOM_30,
		PASS_CUSTOM_31,
		PASS_CUSTOM_32,
		NUM_PASSES,
	};

	enum VIEWPORT_MODE
	{
		VIEWPORT_MODE_DEFAULT,
		VIEWPORT_MODE_PANORAMA_CURVED_180,
		VIEWPORT_MODE_PANORAMA_CURVED_360,
		VIEWPORT_MODE_PANORAMA_LINEAR_180,
		VIEWPORT_MODE_PANORAMA_LINEAR_360,
		VIEWPORT_MODE_PANORAMA_FISHEYE_ORTHOGRAPHIC,
		VIEWPORT_MODE_PANORAMA_FISHEYE_EQUDISTANT,
		VIEWPORT_MODE_PANORAMA_FISHEYE_STEREOGRAPHIC,
		VIEWPORT_MODE_PANORAMA_FISHEYE_EQUISOLID,
		VIEWPORT_MODE_STEREO_ANAGLYPH,
		VIEWPORT_MODE_STEREO_INTERLACED,
		VIEWPORT_MODE_STEREO_HORIZONTAL,
		VIEWPORT_MODE_STEREO_VERTICAL,
		VIEWPORT_MODE_STEREO_SEPARATE,
		VIEWPORT_MODE_STEREO_REPLICATE,
	};

	enum
	{
		ENVIRONMENT_NUM_PRESETS = 3,
	};

	enum GGX_MIPMAPS_QUALITY
	{
		GGX_MIPMAPS_QUALITY_LOW = 0,
		GGX_MIPMAPS_QUALITY_MEDIUM,
		GGX_MIPMAPS_QUALITY_HIGH,
		GGX_MIPMAPS_QUALITY_ULTRA,
	};

	enum MATERIALS_QUALITY
	{
		MATERIALS_QUALITY_LOW = 0,
		MATERIALS_QUALITY_MEDIUM,
		MATERIALS_QUALITY_HIGH,
	};

	enum
	{
		HAZE_DISABLED = 0,
		HAZE_SOLID,
		HAZE_SCATTERING,
	};

	enum VSYNC
	{
		VSYNC_DISABLE,
		VSYNC_STRICT,
		VSYNC_ADAPTIVE,
	};

	enum RENDER_UPSCALE_MODE
	{
		RENDER_UPSCALE_MODE_NONE,
		RENDER_UPSCALE_MODE_FSR,
		RENDER_UPSCALE_MODE_DLSS,
		RENDER_UPSCALE_NUM_MODES,
	};

	enum RENDER_FSR_MODE
	{
		RENDER_FSR_MODE_ULTRA_PERFORMANCE,
		RENDER_FSR_MODE_PERFORMANCE,
		RENDER_FSR_MODE_BALANCED,
		RENDER_FSR_MODE_QUALITY,
		RENDER_FSR_NUM_MODES,
	};

	enum RENDER_DLSS_MODE
	{
		RENDER_DLSS_MODE_ULTRA_PERFORMANCE,
		RENDER_DLSS_MODE_MAX_PERFORMANCE,
		RENDER_DLSS_MODE_BALANCED,
		RENDER_DLSS_MODE_MAX_QUALITY,
		RENDER_DLSS_MODE_DLAA,
		RENDER_DLSS_NUM_MODES,
	};

	enum RENDER_DLSS_PRESET
	{
		RENDER_DLSS_PRESET_DEFAULT,
		RENDER_DLSS_PRESET_A,
		RENDER_DLSS_PRESET_B,
		RENDER_DLSS_PRESET_C,
		RENDER_DLSS_PRESET_D,
		RENDER_DLSS_PRESET_E,
		RENDER_DLSS_PRESET_F,
		RENDER_DLSS_PRESET_G,
		RENDER_DLSS_NUM_PRESETS,
	};
	static bool createMipmapsCubeGGXImage(const Ptr<Image> &image, const Ptr<Texture> &dest, Render::GGX_MIPMAPS_QUALITY quality);
	static bool createMipmapsCubeGGXTexture(const Ptr<Texture> &texture, Render::GGX_MIPMAPS_QUALITY quality, bool realtime = true);
	static int createShorelineDistanceField(const Ptr<Texture> &texture, const Ptr<Image> &mask, int shoreline_radius, int blur_radius, int downsample_resolution);
	static int compressTexture(CallbackBase1<Ptr<Image>> *on_compressed, const Ptr<Texture> &texture, int quality = 1, int new_texture_format = -1, int use_mip_maps = -1);
	static int asyncCompressTexture(CallbackBase1<Ptr<Image>> *on_compressed, CallbackBase1<Ptr<Image>> *on_compressed_async, const Ptr<Texture> &texture, int quality = 1, int new_texture_format = -1, int use_mip_maps = -1);
	static int compressImage(CallbackBase1<Ptr<Image>> *on_compressed, const Ptr<Image> &image, int quality = 1, int new_image_format = -1, int use_mip_maps = -1);
	static int asyncCompressImage(CallbackBase1<Ptr<Image>> *on_compressed, CallbackBase1<Ptr<Image>> *on_compressed_async, const Ptr<Image> &image, int quality = 1, int new_image_format = -1, int use_mip_maps = -1);
	static void transferTextureToImage(CallbackBase1<Ptr<Image>> *on_transfered, const Ptr<Texture> &src);
	static void asyncTransferTextureToImage(CallbackBase1<Ptr<Image>> *on_transfered, CallbackBase1<Ptr<Image>> *on_transfered_async, const Ptr<Texture> &src);
	static void asyncTransferStructuredBuffer(CallbackBase1<void *> *on_transfered, CallbackBase1<void *> *on_transfered_async, const Ptr<StructuredBuffer> &src);
	static void transferStructuredBuffer(CallbackBase1<void *> *on_transfered, const Ptr<StructuredBuffer> &src);
	static void renderTexture2D(const Ptr<Camera> &camera, const Ptr<Texture> &texture, int skip_flags);
	static void renderTexture2D(const Ptr<Camera> &camera, const Ptr<Texture> &texture, int width, int height, int hdr, int skip_flags);
	static void renderTextureCube(const Ptr<Camera> &camera, const Ptr<Texture> &texture, int size, int hdr, int skip_flags, bool local_space = false);
	static void renderTextureCube(const Ptr<Camera> &camera, const Ptr<Texture> &texture, int skip_flags);
	static void renderNodeTexture2D(const Ptr<Camera> &camera, const Ptr<Node> &node, const Ptr<Texture> &texture, int skip_flags, int light_usage, const char *environment_texture_name);
	static void renderNodeTexture2D(const Ptr<Camera> &camera, const Ptr<Node> &node, const Ptr<Texture> &texture, int width, int height, int hdr, int skip_flags, int light_usage, const char *environment_texture_name);
	static void renderScreenMaterial(const char *material_name, const char *texture_name, const Ptr<Texture> &texture);
	static void renderScreenMaterial(const char *material_name, const Ptr<Texture> &color_texture);
	static void renderScreenMaterial(const char *material_name);
	static void renderComputeMaterial(Render::PASS pass, const Ptr<Material> &material, int width, int height, int depth);
	static void renderTAA(const Ptr<Texture> &color_texture, const Ptr<Texture> &color_old_texture);
	static void beginDebugGroup(const char *name);
	static void endDebugGroup();
	static void memoryClear();
	static int getAPI();
	static bool isAPISupported(int api);
	static size_t getMaxTextureBufferSize();
	static bool isFlipped();
	static int getNumInstances();
	static int getMaxFieldSpacers();
	static int getMaxFieldAnimations();
	static int getMaxFieldHeights();
	static int getMaxFieldShorelines();
	static void setEnabled(bool enabled);
	static bool isEnabled();
	static Event<> &getEventBegin();
	static Event<> &getEventBeginEnvironment();
	static Event<> &getEventEndEnvironment();
	static Event<> &getEventBeginShadows();
	static Event<> &getEventBeginWorldShadow();
	static Event<> &getEventEndWorldShadow();
	static Event<> &getEventBeginProjShadow();
	static Event<> &getEventEndProjShadow();
	static Event<> &getEventBeginOmniShadow();
	static Event<> &getEventEndOmniShadow();
	static Event<> &getEventEndShadows();
	static Event<> &getEventBeginScreen();
	static Event<> &getEventBeginMixedRealityBlendMaskColor();
	static Event<> &getEventEndMixedRealityBlendMaskColor();
	static Event<> &getEventBeginOpacityGBuffer();
	static Event<> &getEventEndOpacityGBuffer();
	static Event<> &getEventBeginOpacityDecals();
	static Event<> &getEventEndOpacityDecals();
	static Event<> &getEventBeginCurvature();
	static Event<> &getEventEndCurvature();
	static Event<> &getEventBeginCurvatureComposite();
	static Event<> &getEventEndCurvatureComposite();
	static Event<> &getEventBeginSSRTGI();
	static Event<> &getEventEndSSRTGI();
	static Event<> &getEventBeginOpacityLights();
	static Event<> &getEventEndOpacityLights();
	static Event<> &getEventBeginOpacityVoxelProbes();
	static Event<> &getEventEndOpacityVoxelProbes();
	static Event<> &getEventBeginOpacityEnvironmentProbes();
	static Event<> &getEventEndOpacityEnvironmentProbes();
	static Event<> &getEventBeginOpacityPlanarProbes();
	static Event<> &getEventEndOpacityPlanarProbes();
	static Event<> &getEventBeginAuxiliaryBuffer();
	static Event<> &getEventEndAuxiliaryBuffer();
	static Event<> &getEventBeginRefractionBuffer();
	static Event<> &getEventEndRefractionBuffer();
	static Event<> &getEventBeginTransparentBlurBuffer();
	static Event<> &getEventEndTransparentBlurBuffer();
	static Event<> &getEventBeginSSSS();
	static Event<> &getEventEndSSSS();
	static Event<> &getEventBeginSSR();
	static Event<> &getEventEndSSR();
	static Event<> &getEventBeginSSAO();
	static Event<> &getEventEndSSAO();
	static Event<> &getEventBeginSSGI();
	static Event<> &getEventEndSSGI();
	static Event<> &getEventBeginSky();
	static Event<> &getEventEndSky();
	static Event<> &getEventBeginCompositeDeferred();
	static Event<> &getEventEndCompositeDeferred();
	static Event<> &getEventBeginTransparent();
	static Event<> &getEventBeginClouds();
	static Event<> &getEventEndClouds();
	static Event<> &getEventBeginWater();
	static Event<> &getEventBeginWaterDecals();
	static Event<> &getEventEndWaterDecals();
	static Event<> &getEventBeginWaterLights();
	static Event<> &getEventEndWaterLights();
	static Event<> &getEventBeginWaterVoxelProbes();
	static Event<> &getEventEndWaterVoxelProbes();
	static Event<> &getEventBeginWaterEnvironmentProbes();
	static Event<> &getEventEndWaterEnvironmentProbes();
	static Event<> &getEventBeginWaterPlanarProbes();
	static Event<> &getEventEndWaterPlanarProbes();
	static Event<> &getEventEndWater();
	static Event<> &getEventEndTransparent();
	static Event<> &getEventBeginSrgbCorrection();
	static Event<> &getEventEndSrgbCorrection();
	static Event<> &getEventBeginAdaptationColorAverage();
	static Event<> &getEventEndAdaptationColorAverage();
	static Event<> &getEventBeginAdaptationColor();
	static Event<> &getEventEndAdaptationColor();
	static Event<> &getEventBeginTAA();
	static Event<> &getEventEndTAA();
	static Event<> &getEventBeginCameraEffects();
	static Event<> &getEventEndCameraEffects();
	static Event<> &getEventBeginPostMaterials();
	static Event<> &getEventEndPostMaterials();
	static Event<> &getEventBeginDebugMaterials();
	static Event<> &getEventEndDebugMaterials();
	static Event<> &getEventBeginVisualizer();
	static Event<> &getEventEndVisualizer();
	static Event<> &getEventEndScreen();
	static Event<> &getEventEnd();
	static Event<> &getEventEndFrameExecuteCommandLists();
	static void setData(const char *data);
	static const char *getData();
	static void setFirstFrame(bool frame);
	static bool isFirstFrame();
	static void setClearBufferMask(int mask);
	static int getClearBufferMask();
	static void setShaderDefines(const char *defines);
	static const char *getShaderDefines();
	static void setViewport(const Ptr<Viewport> &viewport);
	static Ptr<Viewport> getViewport();
	static Ptr<Viewport> getViewportMain();
	static bool isViewportModeStereo(Render::VIEWPORT_MODE mode);
	static bool isViewportModePanorama(Render::VIEWPORT_MODE mode);
	static void setCompositeMaterialGUID(const UGUID &compositematerialguid);
	static UGUID getCompositeMaterialGUID();
	static void setDeferredMaterialGUID(const UGUID &deferredmaterialguid);
	static UGUID getDeferredMaterialGUID();
	static void clearDebugMaterials();
	static int getNumDebugMaterials();
	static Ptr<Material> getDebugMaterial(int num);
	static void setDebugMaterial(int num, const Ptr<Material> &material);
	static void insertDebugMaterial(int num, const Ptr<Material> &material);
	static int findDebugMaterial(const Ptr<Material> &material);
	static void addDebugMaterial(const Ptr<Material> &material);
	static void removeDebugMaterial(int num);
	static void swapDebugMaterials(int num_0, int num_1);
	static void setDebugMaterialEnabled(int num, bool enabled);
	static bool getDebugMaterialEnabled(int num);
	static void clearScriptableMaterials();
	static int getNumScriptableMaterials();
	static Ptr<Material> getScriptableMaterial(int num);
	static void setScriptableMaterial(int num, const Ptr<Material> &material);
	static void insertScriptableMaterial(int num, const Ptr<Material> &material);
	static int findScriptableMaterial(const Ptr<Material> &material);
	static void addScriptableMaterial(const Ptr<Material> &material);
	static void removeScriptableMaterial(int num);
	static void swapScriptableMaterials(int num_0, int num_1);
	static void setScriptableMaterialEnabled(int num, bool enabled);
	static bool getScriptableMaterialEnabled(int num);
	static int getNumCompiledPSO();
	static int getNumLoadedPSO();
	static int getNumCompiledShaders();
	static int getNumLoadedShaders();
	static void setBudget(float budget);
	static float getBudget();
	static void setBorder(const Math::vec2 &border);
	static Math::vec2 getBorder();
	static void setMaxFPS(int maxfps);
	static int getMaxFPS();
	static void setVSync(Render::VSYNC vsync);
	static Render::VSYNC getVSync();
	static void setVirtualResolution(const Math::vec2 &resolution);
	static Math::vec2 getVirtualResolution();
	static void setDepthPrePass(bool pass);
	static bool isDepthPrePass();
	static void setGbufferLightmap(bool lightmap);
	static bool isGbufferLightmap();
	static void setDebug(bool debug);
	static bool isDebug();
	static void setMaterialsQuality(Render::MATERIALS_QUALITY quality);
	static Render::MATERIALS_QUALITY getMaterialsQuality();
	static void setLatency(int latency);
	static int getLatency();
	static void setTexturesQuality(int quality);
	static int getTexturesQuality();
	static void setTexturesMaxResolution(int resolution);
	static int getTexturesMaxResolution();
	static void setTexturesMinResolution(int resolution);
	static int getTexturesMinResolution();
	static void setTexturesFilter(int filter);
	static int getTexturesFilter();
	static void setTexturesAnisotropy(int anisotropy);
	static int getTexturesAnisotropy();
	static void setForceStreaming(bool streaming);
	static bool isForceStreaming();
	static void setStreamingFreeSpaceVRAM(int streamingfreespacevram);
	static int getStreamingFreeSpaceVRAM();
	static void setStreamingFreeSpaceRAM(int streamingfreespaceram);
	static int getStreamingFreeSpaceRAM();
	static void setStreamingVRAMOvercommit(bool overcommit);
	static bool isStreamingVRAMOvercommit();
	static void setStreamingVRAMBudget(Render::STREAMING_VRAM_BUDGET budget);
	static Render::STREAMING_VRAM_BUDGET getStreamingVRAMBudget();
	static void setStreamingUsageLimitVRAM(int streamingusagelimitvram);
	static int getStreamingUsageLimitVRAM();
	static void setStreamingUsageLimitRAM(int streamingusagelimitram);
	static int getStreamingUsageLimitRAM();
	static void setStreamingParticlesMemoryLimit(int limit);
	static int getStreamingParticlesMemoryLimit();
	static void setStreamingTexturesMode(Render::STREAMING_MODE mode);
	static Render::STREAMING_MODE getStreamingTexturesMode();
	static void setStreamingTexturesMipmaps(bool mipmaps);
	static bool isStreamingTexturesMipmaps();
	static void setStreamingTexturesMipmapsDensity(float density);
	static float getStreamingTexturesMipmapsDensity();
	static void setStreamingAnimationsLifeTime(int time);
	static int getStreamingAnimationsLifeTime();
	static void setStreamingMeshesModeVRAM(Render::STREAMING_MODE streamingmeshesmodevram);
	static Render::STREAMING_MODE getStreamingMeshesModeVRAM();
	static void setStreamingMeshesModeRAM(Render::STREAMING_MODE streamingmeshesmoderam);
	static Render::STREAMING_MODE getStreamingMeshesModeRAM();
	static void setStreamingMeshesPrefetchCollision(Render::STREAMING_MESHES_PREFETCH collision);
	static Render::STREAMING_MESHES_PREFETCH getStreamingMeshesPrefetchCollision();
	static void setStreamingMeshesPrefetchIntersection(Render::STREAMING_MESHES_PREFETCH intersection);
	static Render::STREAMING_MESHES_PREFETCH getStreamingMeshesPrefetchIntersection();
	static void setStreamingMeshesPrefetchRadius(float radius);
	static float getStreamingMeshesPrefetchRadius();
	static void setShadersCompileMode(Render::SHADERS_COMPILE_MODE mode);
	static Render::SHADERS_COMPILE_MODE getShadersCompileMode();
	static void setDistanceOffset(float offset);
	static float getDistanceOffset();
	static void setDistanceScale(float scale);
	static float getDistanceScale();
	static void setFieldDistance(float distance);
	static float getFieldDistance();
	static void setLightDistance(float distance);
	static float getLightDistance();
	static void setDecalDistance(float distance);
	static float getDecalDistance();
	static void setObjectDistance(float distance);
	static float getObjectDistance();
	static void setReflectionDistance(float distance);
	static float getReflectionDistance();
	static void setShadowDistanceScale(float scale);
	static float getShadowDistanceScale();
	static void setShadowDistance(float distance);
	static float getShadowDistance();
	static void setAnimationStem(float stem);
	static float getAnimationStem();
	static void setAnimationLeaf(float leaf);
	static float getAnimationLeaf();
	static void setAnimationScale(float scale);
	static float getAnimationScale();
	static void setAnimationWind(const Math::vec3 &wind);
	static Math::vec3 getAnimationWind();
	static void setAnimationTime(float time);
	static float getAnimationTime();
	static float getAnimationOldTime();
	static void setVREmulation(int emulation);
	static int getVREmulation();
	static void setViewportMode(Render::VIEWPORT_MODE mode);
	static Render::VIEWPORT_MODE getViewportMode();
	static void setStereoDistance(float distance);
	static float getStereoDistance();
	static void setStereoRadius(float radius);
	static float getStereoRadius();
	static void setStereoOffset(float offset);
	static float getStereoOffset();
	static void setStereoHiddenArea(int area);
	static int getStereoHiddenArea();
	static void setStereoHiddenAreaTransform(const Math::vec4 &transform);
	static Math::vec4 getStereoHiddenAreaTransform();
	static void setStereoHiddenAreaExposureTransform(const Math::vec4 &transform);
	static Math::vec4 getStereoHiddenAreaExposureTransform();
	static void setPanoramaFisheyeFov(float fov);
	static float getPanoramaFisheyeFov();
	static void setAAPreset(int preset);
	static int getAAPreset();
	static int getAAPresetNumNames();
	static const char *getAAPresetName(int num);
	static void setSupersampling(float supersampling);
	static float getSupersampling();
	static void setStereoFocusSupersampling(float supersampling);
	static float getStereoFocusSupersampling();
	static void setTAA(bool taa);
	static bool isTAA();
	static void setTAAPreset(int preset);
	static int getTAAPreset();
	static int getTAAPresetNumNames();
	static const char *getTAAPresetName(int num);
	static void setTAAFixFlicker(bool flicker);
	static bool isTAAFixFlicker();
	static void setTAAAntialiasingInMotion(bool motion);
	static bool isTAAAntialiasingInMotion();
	static void setTAAFramesByColor(bool color);
	static bool isTAAFramesByColor();
	static void setTAAFramesByVelocity(bool velocity);
	static bool isTAAFramesByVelocity();
	static void setTAADiagonalNeighbors(bool neighbors);
	static bool isTAADiagonalNeighbors();
	static void setTAAPreserveDetails(float details);
	static float getTAAPreserveDetails();
	static void setTAAFrameCount(float count);
	static float getTAAFrameCount();
	static void setTAAFramesVelocityThreshold(float threshold);
	static float getTAAFramesVelocityThreshold();
	static void setTAAMaxFramesByVelocity(float velocity);
	static float getTAAMaxFramesByVelocity();
	static void setTAAMinFramesByVelocity(float velocity);
	static float getTAAMinFramesByVelocity();
	static void setTAAPixelOffset(float offset);
	static float getTAAPixelOffset();
	static void setTAACatmullResampling(bool resampling);
	static bool isTAACatmullResampling();
	static void setTAACatmullResamplingSharpness(float sharpness);
	static float getTAACatmullResamplingSharpness();
	static void setTAASamples(int samples);
	static int getTAASamples();
	static void setTAAEdgesFrameCountMultiplier(float multiplier);
	static float getTAAEdgesFrameCountMultiplier();
	static void setTAAInformationLostDepthThreshold(float threshold);
	static float getTAAInformationLostDepthThreshold();
	static void setTAAInformationLostFrameCount(float count);
	static float getTAAInformationLostFrameCount();
	static void setFXAA(bool fxaa);
	static bool isFXAA();
	static void setFXAAIntensity(float intensity);
	static float getFXAAIntensity();
	static void setSRAA(bool sraa);
	static bool isSRAA();
	static void setSRAASamples(int samples);
	static int getSRAASamples();
	static void setSRAATemporal(bool temporal);
	static bool isSRAATemporal();
	static void setSRAADebug(bool debug);
	static bool isSRAADebug();
	static void setSRAADepthThreshold(float threshold);
	static float getSRAADepthThreshold();
	static void setSharpen(bool sharpen);
	static bool isSharpen();
	static void setSharpenIntensity(float intensity);
	static float getSharpenIntensity();
	static void setUpscaleMode(Render::RENDER_UPSCALE_MODE mode);
	static Render::RENDER_UPSCALE_MODE getUpscaleMode();
	static void setUpscalePost(bool post);
	static bool isUpscalePost();
	static void setDLSSMode(Render::RENDER_DLSS_MODE mode);
	static Render::RENDER_DLSS_MODE getDLSSMode();
	static void setDLSSPreset(Render::RENDER_DLSS_PRESET preset);
	static Render::RENDER_DLSS_PRESET getDLSSPreset();
	static void setFSRMode(Render::RENDER_FSR_MODE mode);
	static Render::RENDER_FSR_MODE getFSRMode();
	static void setFSRAutoReactiveEnabled(bool enabled);
	static bool isFSRAutoReactiveEnabled();
	static void setFSREnableSharpness(bool sharpness);
	static bool isFSREnableSharpness();
	static void setFSRSharpness(float sharpness);
	static float getFSRSharpness();
	static void setFSRPreExposure(float exposure);
	static float getFSRPreExposure();
	static void setFSRAutoReactiveScale(float scale);
	static float getFSRAutoReactiveScale();
	static void setFSRAutoTCScale(float scale);
	static float getFSRAutoTCScale();
	static void setFSRAutoTCThreshold(float threshold);
	static float getFSRAutoTCThreshold();
	static void setFSRAutoReactiveMax(float val);
	static float getFSRAutoReactiveMax();
	static void setAlphaFade(bool fade);
	static bool isAlphaFade();
	static void setAuxiliary(bool auxiliary);
	static bool isAuxiliary();
	static void setDecals(bool decals);
	static bool isDecals();
	static void setRefraction(bool refraction);
	static bool isRefraction();
	static void setRefractionDispersion(const Math::vec3 &dispersion);
	static Math::vec3 getRefractionDispersion();
	static void setRefractionWarpBackgroundTransparentSurfaces(int surfaces);
	static int getRefractionWarpBackgroundTransparentSurfaces();
	static void setTransparentBlur(bool blur);
	static bool isTransparentBlur();
	static void setReflectionDynamic(bool dynamic);
	static bool isReflectionDynamic();
	static void setReflectionLods(bool lods);
	static bool isReflectionLods();
	static void setReflectionDynamicRoughnessOffset(bool offset);
	static bool isReflectionDynamicRoughnessOffset();
	static void setSSRTGIPreset(int preset);
	static int getSSRTGIPreset();
	static int getSSRTGIPresetNumNames();
	static const char *getSSRTGIPresetName(int num);
	static void setSSRTGIFastTracing(bool tracing);
	static bool isSSRTGIFastTracing();
	static void setSSRTGIIncreasedAccuracy(bool accuracy);
	static bool isSSRTGIIncreasedAccuracy();
	static void setSSRTGIUpscaling(bool upscaling);
	static bool isSSRTGIUpscaling();
	static void setSSRTGIResolution(int resolution);
	static int getSSRTGIResolution();
	static void setSSRTGIResolutionDepth(int depth);
	static int getSSRTGIResolutionDepth();
	static void setSSRTGINumRays(int rays);
	static int getSSRTGINumRays();
	static void setSSRTGINumSteps(int steps);
	static int getSSRTGINumSteps();
	static void setSSRTGIStepSize(float size);
	static float getSSRTGIStepSize();
	static void setSSAO(bool ssao);
	static bool isSSAO();
	static void setSSAOCavity(bool cavity);
	static bool isSSAOCavity();
	static void setSSAOIntensity(float intensity);
	static float getSSAOIntensity();
	static void setSSAOIntensityReflection(float reflection);
	static float getSSAOIntensityReflection();
	static void setSSAOCavityIntensity(float intensity);
	static float getSSAOCavityIntensity();
	static void setSSAOCavityRadius(float radius);
	static float getSSAOCavityRadius();
	static void setSSAOThreshold(float threshold);
	static float getSSAOThreshold();
	static void setSSGI(bool ssgi);
	static bool isSSGI();
	static void setSSGIIntensity(float intensity);
	static float getSSGIIntensity();
	static void setSSGIThreshold(float threshold);
	static float getSSGIThreshold();
	static void setSSGIIntensityBoost(int boost);
	static int getSSGIIntensityBoost();
	static void setSSGIInformationLostFix(bool fix);
	static bool isSSGIInformationLostFix();
	static void setBentNormal(bool normal);
	static bool isBentNormal();
	static void setBentNormalFixOverlitAreas(bool areas);
	static bool isBentNormalFixOverlitAreas();
	static void setBentNormalThreshold(float threshold);
	static float getBentNormalThreshold();
	static void setSSR(bool ssr);
	static bool isSSR();
	static void setSSRPreset(int preset);
	static int getSSRPreset();
	static int getSSRPresetNumNames();
	static const char *getSSRPresetName(int num);
	static void setSSRIncreasedAccuracy(bool accuracy);
	static bool isSSRIncreasedAccuracy();
	static void setSSRResolution(int resolution);
	static int getSSRResolution();
	static void setSSRResolutionDepth(int depth);
	static int getSSRResolutionDepth();
	static void setSSRResolutionColor(int color);
	static int getSSRResolutionColor();
	static void setSSRAlphaAccumulationMode(int mode);
	static int getSSRAlphaAccumulationMode();
	static void setSSRInformationLostFix(bool fix);
	static bool isSSRInformationLostFix();
	static void setSSRNumRays(int rays);
	static int getSSRNumRays();
	static void setSSRNumSteps(int steps);
	static int getSSRNumSteps();
	static void setSSRNonLinearStepSize(float size);
	static float getSSRNonLinearStepSize();
	static void setSSRPerspectiveCompensation(float compensation);
	static float getSSRPerspectiveCompensation();
	static void setSSRStepSize(float size);
	static float getSSRStepSize();
	static void setSSRVisibilityRoughnessMin(float val);
	static float getSSRVisibilityRoughnessMin();
	static void setSSRVisibilityRoughnessMax(float val);
	static float getSSRVisibilityRoughnessMax();
	static void setSSRRoughnessMipOffset(float offset);
	static float getSSRRoughnessMipOffset();
	static void setSSRThreshold(float threshold);
	static float getSSRThreshold();
	static void setSSRThresholdOcclusion(float occlusion);
	static float getSSRThresholdOcclusion();
	static void setSSRNormalBias(float bias);
	static float getSSRNormalBias();
	static void setSSRViewBias(float bias);
	static float getSSRViewBias();
	static void setSSRTonemappingGamma(float gamma);
	static float getSSRTonemappingGamma();
	static void setIndirectDiffuseTemporalFilteringEnabled(bool enabled);
	static bool isIndirectDiffuseTemporalFilteringEnabled();
	static void setIndirectDiffuseTemporalFilteringFrameCount(float count);
	static float getIndirectDiffuseTemporalFilteringFrameCount();
	static void setIndirectDiffuseTemporalFilteringFrameCountMin(float val);
	static float getIndirectDiffuseTemporalFilteringFrameCountMin();
	static void setIndirectDiffuseTemporalFilteringColorClampingIntensity(float intensity);
	static float getIndirectDiffuseTemporalFilteringColorClampingIntensity();
	static void setIndirectDiffuseTemporalFilteringColorClampingIntensityAO(float indirectdiffusetemporalfilteringcolorclampingintensityao);
	static float getIndirectDiffuseTemporalFilteringColorClampingIntensityAO();
	static void setIndirectDiffuseTemporalFilteringColorClampingVelocityThreshold(float threshold);
	static float getIndirectDiffuseTemporalFilteringColorClampingVelocityThreshold();
	static void setIndirectDiffuseTemporalFilteringFramesClampingVelocityThreshold(float threshold);
	static float getIndirectDiffuseTemporalFilteringFramesClampingVelocityThreshold();
	static void setIndirectDiffuseDenoiseEnabled(bool enabled);
	static bool isIndirectDiffuseDenoiseEnabled();
	static void setIndirectDiffuseDenoiseMaskEnabled(bool enabled);
	static bool isIndirectDiffuseDenoiseMaskEnabled();
	static void setIndirectDiffuseDenoiseThreshold(float threshold);
	static float getIndirectDiffuseDenoiseThreshold();
	static void setIndirectDiffuseDenoiseThresholdAO(float indirectdiffusedenoisethresholdao);
	static float getIndirectDiffuseDenoiseThresholdAO();
	static void setIndirectSpecularTemporalFilteringEnabled(bool enabled);
	static bool isIndirectSpecularTemporalFilteringEnabled();
	static void setIndirectSpecularTemporalFilteringFrameCount(float count);
	static float getIndirectSpecularTemporalFilteringFrameCount();
	static void setIndirectSpecularTemporalFilteringFrameCountMin(float val);
	static float getIndirectSpecularTemporalFilteringFrameCountMin();
	static void setIndirectSpecularTemporalFilteringColorClampingIntensity(float intensity);
	static float getIndirectSpecularTemporalFilteringColorClampingIntensity();
	static void setIndirectSpecularTemporalFilteringColorClampingIntensityAO(float indirectspeculartemporalfilteringcolorclampingintensityao);
	static float getIndirectSpecularTemporalFilteringColorClampingIntensityAO();
	static void setIndirectSpecularTemporalFilteringColorClampingVelocityThreshold(float threshold);
	static float getIndirectSpecularTemporalFilteringColorClampingVelocityThreshold();
	static void setIndirectSpecularTemporalFilteringFramesClampingVelocityThreshold(float threshold);
	static float getIndirectSpecularTemporalFilteringFramesClampingVelocityThreshold();
	static void setIndirectSpecularDenoiseEnabled(bool enabled);
	static bool isIndirectSpecularDenoiseEnabled();
	static void setIndirectSpecularDenoiseMaskEnabled(bool enabled);
	static bool isIndirectSpecularDenoiseMaskEnabled();
	static void setIndirectSpecularDenoiseThreshold(float threshold);
	static float getIndirectSpecularDenoiseThreshold();
	static void setIndirectSpecularDenoiseThresholdAO(float indirectspeculardenoisethresholdao);
	static float getIndirectSpecularDenoiseThresholdAO();
	static void setDenoisePreset(int preset);
	static int getDenoisePreset();
	static int getDenoisePresetNumNames();
	static const char *getDenoisePresetName(int num);
	static void setDenoiseInterleaved(bool interleaved);
	static bool isDenoiseInterleaved();
	static void setDenoiseRadius(int radius);
	static int getDenoiseRadius();
	static void setDenoiseNumBlurIterations(int iterations);
	static int getDenoiseNumBlurIterations();
	static void setDenoiseInformationLostDepthThreshold(float threshold);
	static float getDenoiseInformationLostDepthThreshold();
	static void setDenoiseWrongVelocityFixByDepthEnabled(bool enabled);
	static bool isDenoiseWrongVelocityFixByDepthEnabled();
	static void setDenoiseWrongVelocityFixByDepthThreshold(float threshold);
	static float getDenoiseWrongVelocityFixByDepthThreshold();
	static void setDenoiseAOMaskRadius(float radius);
	static float getDenoiseAOMaskRadius();
	static void setDenoiseColorClampingBlurResolution(int resolution);
	static int getDenoiseColorClampingBlurResolution();
	static void setDenoiseColorClampingBlurRadius(float radius);
	static float getDenoiseColorClampingBlurRadius();
	static void setDenoiseColorClampingBlurIntensity(float intensity);
	static float getDenoiseColorClampingBlurIntensity();
	static void setDenoiseColorClampingBlurIntensityAO(float denoisecolorclampingblurintensityao);
	static float getDenoiseColorClampingBlurIntensityAO();
	static void setDenoiseInformationLostFixFlicker(float flicker);
	static float getDenoiseInformationLostFixFlicker();
	static void setDenoiseHotPixelsFixIntensity(float intensity);
	static float getDenoiseHotPixelsFixIntensity();
	static void setDenoiseDenoiseMaskFrameCount(float count);
	static float getDenoiseDenoiseMaskFrameCount();
	static void setDenoiseDenoiseMaskVelocityThreshold(float threshold);
	static float getDenoiseDenoiseMaskVelocityThreshold();
	static void setDenoiseDenoiseMaskInformationLostBoost(float boost);
	static float getDenoiseDenoiseMaskInformationLostBoost();
	static void setDenoiseDenoiseMaskBias(float bias);
	static float getDenoiseDenoiseMaskBias();
	static void setDenoiseDenoiseMaskDenoiseThreshold(float threshold);
	static float getDenoiseDenoiseMaskDenoiseThreshold();
	static void setSSSSS(bool sssss);
	static bool isSSSSS();
	static void setSSSSSPreset(int preset);
	static int getSSSSSPreset();
	static int getSSSSSPresetNumNames();
	static const char *getSSSSSPresetName(int num);
	static void setSSSSSQuality(int quality);
	static int getSSSSSQuality();
	static void setSSSSSResolution(int resolution);
	static int getSSSSSResolution();
	static void setSSSSSRadius(float radius);
	static float getSSSSSRadius();
	static void setSSSSSColor(const Math::vec4 &color);
	static Math::vec4 getSSSSSColor();
	static void setSSSSSDiffuse(bool diffuse);
	static bool isSSSSSDiffuse();
	static void setSSSSSAmbient(bool ambient);
	static bool isSSSSSAmbient();
	static void setSSSSSMinThreshold(float threshold);
	static float getSSSSSMinThreshold();
	static void setSSSSSMaxThreshold(float threshold);
	static float getSSSSSMaxThreshold();
	static void setSSSSSNoiseStep(float step);
	static float getSSSSSNoiseStep();
	static void setSSSSSNoiseRay(float ray);
	static float getSSSSSNoiseRay();
	static void setSSSSSInterleaved(bool interleaved);
	static bool isSSSSSInterleaved();
	static void setSSSSSInterleavedColorClamping(int clamping);
	static int getSSSSSInterleavedColorClamping();
	static void setSSSSSInterleavedSamples(int samples);
	static int getSSSSSInterleavedSamples();
	static void setSSSSSTAA(bool ssssstaa);
	static bool isSSSSSTAA();
	static void setSSSSSTAAFixFlicker(bool flicker);
	static bool isSSSSSTAAFixFlicker();
	static void setSSSSSTAAAntialiasingInMotion(bool motion);
	static bool isSSSSSTAAAntialiasingInMotion();
	static void setSSSSSTAAFramesByColor(bool color);
	static bool isSSSSSTAAFramesByColor();
	static void setSSSSSTAAFramesByVelocity(bool velocity);
	static bool isSSSSSTAAFramesByVelocity();
	static void setSSSSSTAAPreserveDetails(float details);
	static float getSSSSSTAAPreserveDetails();
	static void setSSSSSTAAFrameCount(float count);
	static float getSSSSSTAAFrameCount();
	static void setSSSSSTAAFramesVelocityThreshold(float threshold);
	static float getSSSSSTAAFramesVelocityThreshold();
	static void setSSSSSTAAMaxFramesByVelocity(float velocity);
	static float getSSSSSTAAMaxFramesByVelocity();
	static void setSSSSSTAAMinFramesByVelocity(float velocity);
	static float getSSSSSTAAMinFramesByVelocity();
	static void setSSSSSTAAPixelOffset(float offset);
	static float getSSSSSTAAPixelOffset();
	static void setSSSSSTAACatmullResampling(bool resampling);
	static bool isSSSSSTAACatmullResampling();
	static void setSSSSSTAASamples(int samples);
	static int getSSSSSTAASamples();
	static void setTranslucentColor(const Math::vec4 &color);
	static Math::vec4 getTranslucentColor();
	static void setCameraEffectsThreshold(float threshold);
	static float getCameraEffectsThreshold();
	static void setCameraEffectsTemporalFiltering(bool filtering);
	static bool isCameraEffectsTemporalFiltering();
	static void setCameraEffectsTemporalFilteringColorClampingIntensity(float intensity);
	static float getCameraEffectsTemporalFilteringColorClampingIntensity();
	static void setCameraEffectsTemporalFilteringMinVelocityClamping(float clamping);
	static float getCameraEffectsTemporalFilteringMinVelocityClamping();
	static void setCameraEffectsTemporalFilteringMaxVelocityClamping(float clamping);
	static float getCameraEffectsTemporalFilteringMaxVelocityClamping();
	static void setDirtScale(float scale);
	static float getDirtScale();
	static void setDirtTextureName(const char *name);
	static const char *getDirtTextureName();
	static void setMeteringMaskEnabled(bool enabled);
	static bool isMeteringMaskEnabled();
	static void setMeteringMaskTexturePath(const char *path);
	static const char *getMeteringMaskTexturePath();
	static Ptr<Texture> getMeteringMaskTexture();
	static void setCameraMode(Render::CAMERA_MODE mode);
	static Render::CAMERA_MODE getCameraMode();
	static void setISO(float iso);
	static float getISO();
	static void setShutterSpeed(float speed);
	static float getShutterSpeed();
	static void setFStop(float fstop);
	static float getFStop();
	static void setExposureMode(Render::EXPOSURE_MODE mode);
	static Render::EXPOSURE_MODE getExposureMode();
	static void setExposure(float exposure);
	static float getExposure();
	static void setExposureAdaptation(float adaptation);
	static float getExposureAdaptation();
	static void setExposureMinLuminance(float luminance);
	static float getExposureMinLuminance();
	static void setExposureMaxLuminance(float luminance);
	static float getExposureMaxLuminance();
	static Ptr<TextureRamp> getAutoExposureRamp();
	static void resetAutoExposureRamp();
	static void setWhiteBalance(bool balance);
	static bool isWhiteBalance();
	static void setWhiteBalanceIntensity(float intensity);
	static float getWhiteBalanceIntensity();
	static void setWhiteBalanceAdaptationTime(float time);
	static float getWhiteBalanceAdaptationTime();
	static void setMotionBlur(bool blur);
	static bool isMotionBlur();
	static void setMotionBlurPreset(int preset);
	static int getMotionBlurPreset();
	static int getMotionBlurPresetNumNames();
	static const char *getMotionBlurPresetName(int num);
	static void setMotionBlurCameraVelocity(bool velocity);
	static bool isMotionBlurCameraVelocity();
	static void setMotionBlurVelocityScale(float scale);
	static float getMotionBlurVelocityScale();
	static void setMotionBlurMaxVelocity(float velocity);
	static float getMotionBlurMaxVelocity();
	static void setMotionBlurNoiseIntensity(float intensity);
	static float getMotionBlurNoiseIntensity();
	static void setMotionBlurNumSteps(int steps);
	static int getMotionBlurNumSteps();
	static void setMotionBlurVelocityBlurSamples(int samples);
	static int getMotionBlurVelocityBlurSamples();
	static void setMotionBlurVelocityBlurRadius(float radius);
	static float getMotionBlurVelocityBlurRadius();
	static void setMotionBlurDepthThresholdNear(float val);
	static float getMotionBlurDepthThresholdNear();
	static void setMotionBlurDepthThresholdFar(float val);
	static float getMotionBlurDepthThresholdFar();
	static void setDOF(bool dof);
	static bool isDOF();
	static void setDOFPreset(int preset);
	static int getDOFPreset();
	static int getDOFPresetNumNames();
	static const char *getDOFPresetName(int num);
	static void setDOFIncreasedAccuracy(bool accuracy);
	static bool isDOFIncreasedAccuracy();
	static void setDOFFocusImprovement(bool improvement);
	static bool isDOFFocusImprovement();
	static void setDOFQuality(int quality);
	static int getDOFQuality();
	static void setDOFResolution(int resolution);
	static int getDOFResolution();
	static void setDOFBokehMode(int mode);
	static int getDOFBokehMode();
	static void setDOFFocalDistance(float distance);
	static float getDOFFocalDistance();
	static void setDOFChromaticAberration(float aberration);
	static float getDOFChromaticAberration();
	static void setDOFBlur(float blur);
	static float getDOFBlur();
	static void setDOFFarDistance(float distance);
	static float getDOFFarDistance();
	static void setDOFFarFocalOffset(float offset);
	static float getDOFFarFocalOffset();
	static void setDOFNearDistance(float distance);
	static float getDOFNearDistance();
	static void setDOFNearFocalOffset(float offset);
	static float getDOFNearFocalOffset();
	static void setBloom(bool bloom);
	static bool isBloom();
	static void setBloomResolution(int resolution);
	static int getBloomResolution();
	static void setBloomPasses(int passes);
	static int getBloomPasses();
	static void setBloomScale(float scale);
	static float getBloomScale();
	static void setBloomPower(float power);
	static float getBloomPower();
	static void setLocalTonemapper(bool tonemapper);
	static bool isLocalTonemapper();
	static void setLocalTonemapperDebug(bool debug);
	static bool isLocalTonemapperDebug();
	static void setLocalTonemapperBlurResolution(int resolution);
	static int getLocalTonemapperBlurResolution();
	static void setLocalTonemapperBlurUpscale(bool upscale);
	static bool isLocalTonemapperBlurUpscale();
	static void setLocalTonemapperBlurUpscaleKernelSize(int size);
	static int getLocalTonemapperBlurUpscaleKernelSize();
	static void setLocalTonemapperNumBlurIterations(int iterations);
	static int getLocalTonemapperNumBlurIterations();
	static void setLocalTonemapperTonemappingIntensity(float intensity);
	static float getLocalTonemapperTonemappingIntensity();
	static void setLocalTonemapperEffectOnDarkAreas(float areas);
	static float getLocalTonemapperEffectOnDarkAreas();
	static void setLocalTonemapperEffectOnDarkAreasGamma(float gamma);
	static float getLocalTonemapperEffectOnDarkAreasGamma();
	static void setLocalTonemapperTargetMiddleGray(float gray);
	static float getLocalTonemapperTargetMiddleGray();
	static void setLocalTonemapperLumaBlurredIntensity(float intensity);
	static float getLocalTonemapperLumaBlurredIntensity();
	static void setLocalTonemapperDepthDifferenceEnabled(bool enabled);
	static bool isLocalTonemapperDepthDifferenceEnabled();
	static void setLocalTonemapperDepthThreshold(float threshold);
	static float getLocalTonemapperDepthThreshold();
	static void setLocalTonemapperColorDifferenceEnabled(bool enabled);
	static bool isLocalTonemapperColorDifferenceEnabled();
	static void setLocalTonemapperColorDifferenceThreshold(float threshold);
	static float getLocalTonemapperColorDifferenceThreshold();
	static void setTonemapper(bool tonemapper);
	static bool isTonemapper();
	static void setTonemapperMode(Render::TONEMAPPER mode);
	static Render::TONEMAPPER getTonemapperMode();
	static void setFilmicShoulderScale(float scale);
	static float getFilmicShoulderScale();
	static void setFilmicLinearScale(float scale);
	static float getFilmicLinearScale();
	static void setFilmicLinearAngle(float angle);
	static float getFilmicLinearAngle();
	static void setFilmicToeScale(float scale);
	static float getFilmicToeScale();
	static void setFilmicToeNumerator(float numerator);
	static float getFilmicToeNumerator();
	static void setFilmicToeDenominator(float denominator);
	static float getFilmicToeDenominator();
	static void setFilmicWhiteLevel(float level);
	static float getFilmicWhiteLevel();
	static void setFilmicSaturationRecovery(float recovery);
	static float getFilmicSaturationRecovery();
	static void setReinhardContribution(float contribution);
	static float getReinhardContribution();
	static void setReinhardLumaBasedContribution(float contribution);
	static float getReinhardLumaBasedContribution();
	static void setACESWithReinhardMix(float mix);
	static float getACESWithReinhardMix();
	static void setACESWhiteClip(float clip);
	static float getACESWhiteClip();
	static void setACESToe(float toe);
	static float getACESToe();
	static void setACESShoulderAngle(float angle);
	static float getACESShoulderAngle();
	static void setACESShoulderStrength(float strength);
	static float getACESShoulderStrength();
	static void setACESShoulderLength(float length);
	static float getACESShoulderLength();
	static void setACESWithReinhardWhiteClip(float clip);
	static float getACESWithReinhardWhiteClip();
	static void setACESWithReinhardToe(float toe);
	static float getACESWithReinhardToe();
	static void setACESWithReinhardShoulderAngle(float angle);
	static float getACESWithReinhardShoulderAngle();
	static void setACESWithReinhardShoulderStrength(float strength);
	static float getACESWithReinhardShoulderStrength();
	static void setACESWithReinhardShoulderLength(float length);
	static float getACESWithReinhardShoulderLength();
	static void setChromaticAberration(bool aberration);
	static bool isChromaticAberration();
	static void setChromaticAberrationIntensity(float intensity);
	static float getChromaticAberrationIntensity();
	static void setChromaticAberrationNoiseIntensity(float intensity);
	static float getChromaticAberrationNoiseIntensity();
	static void setChromaticAberrationSamples(int samples);
	static int getChromaticAberrationSamples();
	static void setNoise(bool noise);
	static bool isNoise();
	static void setNoiseIntensity(float intensity);
	static float getNoiseIntensity();
	static void setVignetteMask(bool mask);
	static bool isVignetteMask();
	static void setVignetteMaskIntensity(float intensity);
	static float getVignetteMaskIntensity();
	static void setVignetteMaskPower(float power);
	static float getVignetteMaskPower();
	static void setVignetteMaskTexturePath(const char *path);
	static const char *getVignetteMaskTexturePath();
	static void setCross(bool cross);
	static bool isCross();
	static void setCrossShafts(int shafts);
	static int getCrossShafts();
	static void setCrossLength(float length);
	static float getCrossLength();
	static void setCrossScale(float scale);
	static float getCrossScale();
	static void setCrossAngle(float angle);
	static float getCrossAngle();
	static void setCrossThreshold(float threshold);
	static float getCrossThreshold();
	static void setCrossColor(const Math::vec4 &color);
	static Math::vec4 getCrossColor();
	static void setLens(bool lens);
	static bool isLens();
	static void setLensScale(float scale);
	static float getLensScale();
	static void setLensLength(float length);
	static float getLensLength();
	static void setLensRadius(float radius);
	static float getLensRadius();
	static void setLensThreshold(float threshold);
	static float getLensThreshold();
	static void setLensColor(const Math::vec4 &color);
	static Math::vec4 getLensColor();
	static void setLensDispersion(const Math::vec3 &dispersion);
	static Math::vec3 getLensDispersion();
	static void setWireframeColor(const Math::vec4 &color);
	static Math::vec4 getWireframeColor();
	static void setBackgroundColor(const Math::vec4 &color);
	static Math::vec4 getBackgroundColor();
	static void setFadeColor(const Math::vec4 &color);
	static Math::vec4 getFadeColor();
	static void setWireframeAntialiasing(bool antialiasing);
	static bool isWireframeAntialiasing();
	static void setFfpAntialiasingLines(bool lines);
	static bool isFfpAntialiasingLines();
	static void setColorCorrectionBrightness(float brightness);
	static float getColorCorrectionBrightness();
	static void setColorCorrectionContrast(float contrast);
	static float getColorCorrectionContrast();
	static void setColorCorrectionGamma(float gamma);
	static float getColorCorrectionGamma();
	static void setColorCorrectionWhite(const Math::vec4 &white);
	static Math::vec4 getColorCorrectionWhite();
	static int setColorCorrectionLUTImage(const Ptr<Image> &image);
	static int getColorCorrectionLUTImage(Ptr<Image> &image);
	static void setColorCorrectionLUTPath(const char *path);
	static const char *getColorCorrectionLUTPath();
	static void setColorCorrectionPreserveSaturation(bool saturation);
	static bool isColorCorrectionPreserveSaturation();
	static void setColorCorrectionByCurves(bool curves);
	static bool isColorCorrectionByCurves();
	static void setColorCorrectionSaturationPerColor(bool color);
	static bool isColorCorrectionSaturationPerColor();
	static void setColorCorrectionHuePerColor(bool color);
	static bool isColorCorrectionHuePerColor();
	static void setMultithreaded(bool multithreaded);
	static bool isMultithreaded();
	static Ptr<TextureRamp> getColorCorrectionRamp();
	static void resetColorCorrectionRamp();
	static void resetColorCorrectionSaturationRamp();
	static void setColorCorrectionSaturationIndex(int index, float value);
	static float getColorCorrectionSaturationIndex(int index);
	static void setColorCorrectionHueShiftIndex(int index, float value);
	static float getColorCorrectionHueShiftIndex(int index);
	static void setColorCorrectionSaturation(const Palette &saturation);
	static Palette getColorCorrectionSaturation();
	static void setColorCorrectionHueShift(const Palette &shift);
	static Palette getColorCorrectionHueShift();
	static void setEnvironment(bool environment);
	static bool isEnvironment();
	static void setEnvironmentHemisphere(bool hemisphere);
	static bool isEnvironmentHemisphere();
	static void setEnvironmentHazeMode(int mode);
	static int getEnvironmentHazeMode();
	static void setEnvironmentHazeGradient(int gradient);
	static int getEnvironmentHazeGradient();
	static void setEnvironmentHazeScreenSpaceGlobalIllumination(bool illumination);
	static bool isEnvironmentHazeScreenSpaceGlobalIllumination();
	static void setEnvironmentHazeScreenSpaceGlobalIlluminationDistanceMin(float val);
	static float getEnvironmentHazeScreenSpaceGlobalIlluminationDistanceMin();
	static void setEnvironmentHazeScreenSpaceGlobalIlluminationDistanceMax(float val);
	static float getEnvironmentHazeScreenSpaceGlobalIlluminationDistanceMax();
	static void setEnvironmentHazeTemporalFilter(bool filter);
	static bool isEnvironmentHazeTemporalFilter();
	static void setEnvironmentHazeColorizationThreshold(float threshold);
	static float getEnvironmentHazeColorizationThreshold();
	static void setEnvironmentHazeColorizationIntensity(float intensity);
	static float getEnvironmentHazeColorizationIntensity();
	static void setEnvironmentCubemapBlendMode(int mode);
	static int getEnvironmentCubemapBlendMode();
	static void setEnvironmentGGXMipmapsQuality(Render::GGX_MIPMAPS_QUALITY quality);
	static Render::GGX_MIPMAPS_QUALITY getEnvironmentGGXMipmapsQuality();
	static void setScreenSpaceShadowShaftsMode(int mode);
	static int getScreenSpaceShadowShaftsMode();
	static void setScreenSpaceShadowShaftsResolution(int resolution);
	static int getScreenSpaceShadowShaftsResolution();
	static void setScreenSpaceShadowShaftsQuality(int quality);
	static int getScreenSpaceShadowShaftsQuality();
	static void setScreenSpaceShadowShaftsLength(float length);
	static float getScreenSpaceShadowShaftsLength();
	static Ptr<RenderEnvironmentPreset> getEnvironmentPreset(int num);
	static Math::vec4 getEnvironmentHazeColor();
	static float getEnvironmentHazeMaxDistance();
	static float getEnvironmentHazeDensity();
	static float getEnvironmentHazePhysicalStartHeight();
	static float getEnvironmentHazePhysicalHalfVisibilityDistance();
	static float getEnvironmentHazePhysicalHalfFalloffHeight();
	static float getEnvironmentHazePhysicalAmbientLightIntensity();
	static float getEnvironmentHazePhysicalAmbientColorSaturation();
	static float getEnvironmentHazePhysicalSunLightIntensity();
	static float getEnvironmentHazePhysicalSunColorSaturation();
	static float getEnvironmentHazeScatteringMieIntensity();
	static float getEnvironmentHazeScatteringMieFrontSideIntensity();
	static float getEnvironmentHazeScatteringMieFresnelPower();
	static float getEnvironmentAmbientIntensity();
	static float getEnvironmentReflectionIntensity();
	static float getEnvironmentSkyIntensity();
	static void setSkyRotation(const Math::quat &rotation);
	static Math::quat getSkyRotation();
	static void setOcclusionQueries(bool queries);
	static bool isOcclusionQueries();
	static void setOcclusionQueriesNumFrames(int frames);
	static int getOcclusionQueriesNumFrames();
	static void setOccluders(bool occluders);
	static bool isOccluders();
	static void setOccludersResolution(const Math::vec2 &resolution);
	static Math::vec2 getOccludersResolution();
	static void setOccludersShadows(bool shadows);
	static bool isOccludersShadows();
	static void setOccludersShadowsResolution(const Math::vec2 &resolution);
	static Math::vec2 getOccludersShadowsResolution();
	static void setLightsEnabled(bool enabled);
	static bool isLightsEnabled();
	static void setLightsMaxPerBatch(int batch);
	static int getLightsMaxPerBatch();
	static void setLightsTileGridSize(int size);
	static int getLightsTileGridSize();
	static void setLightsForwardPerObjectWorld(int world);
	static int getLightsForwardPerObjectWorld();
	static void setLightsForwardPerObjectOmni(int omni);
	static int getLightsForwardPerObjectOmni();
	static void setLightsForwardPerObjectProj(int proj);
	static int getLightsForwardPerObjectProj();
	static void setLightsForwardPerObjectEnv(int env);
	static int getLightsForwardPerObjectEnv();
	static void setLightsForwardPerObjectPlanar(int planar);
	static int getLightsForwardPerObjectPlanar();
	static void setLightsForwardPerObjectVoxel(int voxel);
	static int getLightsForwardPerObjectVoxel();
	static void setLightsLensFlares(bool flares);
	static bool isLightsLensFlares();
	static void setDirectLightingInterleaved(bool interleaved);
	static bool isDirectLightingInterleaved();
	static void setDirectLightingInterleavedCatmullResampling(bool resampling);
	static bool isDirectLightingInterleavedCatmullResampling();
	static void setDirectLightingInterleavedColorClamping(int clamping);
	static int getDirectLightingInterleavedColorClamping();
	static void setDirectLightingInterleavedSamples(int samples);
	static int getDirectLightingInterleavedSamples();
	static void setIndirectLightingInterleaved(bool interleaved);
	static bool isIndirectLightingInterleaved();
	static void setIndirectLightingInterleavedCatmullResampling(bool resampling);
	static bool isIndirectLightingInterleavedCatmullResampling();
	static void setIndirectLightingInterleavedColorClamping(int clamping);
	static int getIndirectLightingInterleavedColorClamping();
	static void setIndirectLightingInterleavedColorClampingIntensity(float intensity);
	static float getIndirectLightingInterleavedColorClampingIntensity();
	static void setIndirectLightingInterleavedColorClampingVelocityThreshold(float threshold);
	static float getIndirectLightingInterleavedColorClampingVelocityThreshold();
	static void setIndirectLightingInterleavedSamples(int samples);
	static int getIndirectLightingInterleavedSamples();
	static void setLightmapColor(const Math::vec4 &color);
	static Math::vec4 getLightmapColor();
	static void setShadows(bool shadows);
	static bool isShadows();
	static void setShadowsReuse(bool reuse);
	static bool isShadowsReuse();
	static void setShadowsTranslucentDepth(float depth);
	static float getShadowsTranslucentDepth();
	static void setShadowsWorldLerpCascades(bool cascades);
	static bool isShadowsWorldLerpCascades();
	static void setShadowsWorldCascadesCullingClusters(bool clusters);
	static bool isShadowsWorldCascadesCullingClusters();
	static void setShadowsAlphaTest(bool test);
	static bool isShadowsAlphaTest();
	static void setShadowsSimplified(bool simplified);
	static bool isShadowsSimplified();
	static void setShadowsScreenSpace(bool space);
	static bool isShadowsScreenSpace();
	static void setShadowsPenumbraMode(int mode);
	static int getShadowsPenumbraMode();
	static void setShadowsPenumbraNoise(bool noise);
	static bool isShadowsPenumbraNoise();
	static void setShadowsFilterMode(int mode);
	static int getShadowsFilterMode();
	static void setShadowsFilterNoise(bool noise);
	static bool isShadowsFilterNoise();
	static void setScreenPrecision(bool precision);
	static bool isScreenPrecision();
	static void setSSBevel(bool bevel);
	static bool isSSBevel();
	static void setSSBevelVertexNormal(int normal);
	static int getSSBevelVertexNormal();
	static void setSSBevelQuality(int quality);
	static int getSSBevelQuality();
	static void setSSBevelNoise(bool noise);
	static bool isSSBevelNoise();
	static void setSSBevelRadius(float radius);
	static float getSSBevelRadius();
	static void setSSDirt(bool dirt);
	static bool isSSDirt();
	static void setSSDirtQuality(int quality);
	static int getSSDirtQuality();
	static void setSSDirtResolution(int resolution);
	static int getSSDirtResolution();
	static void setSSDirtIntensity(float intensity);
	static float getSSDirtIntensity();
	static void setSSDirtRadius(float radius);
	static float getSSDirtRadius();
	static void setSSDirtThreshold(float threshold);
	static float getSSDirtThreshold();
	static void setSSDirtAngleBias(float bias);
	static float getSSDirtAngleBias();
	static void setSSDirtPerspective(float perspective);
	static float getSSDirtPerspective();
	static void setSSDirtIncreaseAccuracy(bool accuracy);
	static bool isSSDirtIncreaseAccuracy();
	static void setSSDirtCavityAlbedoTextureName(const char *name);
	static const char *getSSDirtCavityAlbedoTextureName();
	static void setSSDirtCavityShadingTextureName(const char *name);
	static const char *getSSDirtCavityShadingTextureName();
	static void setSSDirtConvexityAlbedoTextureName(const char *name);
	static const char *getSSDirtConvexityAlbedoTextureName();
	static void setSSDirtConvexityShadingTextureName(const char *name);
	static const char *getSSDirtConvexityShadingTextureName();
	static void setSSDirtCavityTextureSize(float size);
	static float getSSDirtCavityTextureSize();
	static void setSSDirtCavityColor(const Math::vec4 &color);
	static Math::vec4 getSSDirtCavityColor();
	static void setSSDirtCavityExponent(float exponent);
	static float getSSDirtCavityExponent();
	static void setSSDirtCavityMetalness(float metalness);
	static float getSSDirtCavityMetalness();
	static void setSSDirtCavityMetalnessVisibility(float visibility);
	static float getSSDirtCavityMetalnessVisibility();
	static void setSSDirtConvexityTextureSize(float size);
	static float getSSDirtConvexityTextureSize();
	static void setSSDirtConvexityColor(const Math::vec4 &color);
	static Math::vec4 getSSDirtConvexityColor();
	static void setSSDirtConvexityExponent(float exponent);
	static float getSSDirtConvexityExponent();
	static void setSSDirtConvexityMetalness(float metalness);
	static float getSSDirtConvexityMetalness();
	static void setSSDirtConvexityMetalnessVisibility(float visibility);
	static float getSSDirtConvexityMetalnessVisibility();
	static void setLandscapeTerrainGeometryPreset(int preset);
	static int getLandscapeTerrainGeometryPreset();
	static int getLandscapeTerrainGeometryPresetNumNames();
	static const char *getLandscapeTerrainGeometryPresetName(int num);
	static void setLandscapeTerrainStreamingPreset(int preset);
	static int getLandscapeTerrainStreamingPreset();
	static int getLandscapeTerrainStreamingPresetNumNames();
	static const char *getLandscapeTerrainStreamingPresetName(int num);
	static void setLandscapeTerrainVisibleDistance(float distance);
	static float getLandscapeTerrainVisibleDistance();
	static void setLandscapeTerrainTexelSize(float size);
	static float getLandscapeTerrainTexelSize();
	static void setLandscapeTerrainVTMemorySize(float size);
	static float getLandscapeTerrainVTMemorySize();
	static void setLandscapeTerrainVTTargetResolution(const Math::vec2 &resolution);
	static Math::vec2 getLandscapeTerrainVTTargetResolution();
	static void setLandscapeTerrainVTDetailLevelByAngle(float angle);
	static float getLandscapeTerrainVTDetailLevelByAngle();
	static void setLandscapeTerrainVTFiltering(int filtering);
	static int getLandscapeTerrainVTFiltering();
	static void setLandscapeTerrainVTTilesUpdatePerFrame(int frame);
	static int getLandscapeTerrainVTTilesUpdatePerFrame();
	static void setLandscapeTerrainVTTilesLoadPerFrame(int frame);
	static int getLandscapeTerrainVTTilesLoadPerFrame();
	static void setLandscapeTerrainVTTilesReloadPerFrame(int frame);
	static int getLandscapeTerrainVTTilesReloadPerFrame();
	static void setLandscapeTerrainVTSamplerFeedbackScreenResolution(int resolution);
	static int getLandscapeTerrainVTSamplerFeedbackScreenResolution();
	static void setLandscapeTerrainVTSamplerFeedbackBufferResolution(const Math::vec2 &resolution);
	static Math::vec2 getLandscapeTerrainVTSamplerFeedbackBufferResolution();
	static void setLandscapeTerrainVTHashSize(int size);
	static int getLandscapeTerrainVTHashSize();
	static void setLandscapeTerrainVTHashSizeNumberMistakes(int mistakes);
	static int getLandscapeTerrainVTHashSizeNumberMistakes();
	static void setLandscapeTerrainStreamingThreads(int threads);
	static int getLandscapeTerrainStreamingThreads();
	static void setLandscapeTerrainStreamingPerLods(bool lods);
	static bool isLandscapeTerrainStreamingPerLods();
	static void setLandscapeTerrainDetailResolutionAlbedo(int albedo);
	static int getLandscapeTerrainDetailResolutionAlbedo();
	static void setLandscapeTerrainDetailResolutionHeight(int height);
	static int getLandscapeTerrainDetailResolutionHeight();
	static void setLandscapeTerrainDetailResolutionAdditionalMask(int mask);
	static int getLandscapeTerrainDetailResolutionAdditionalMask();
	static void setLandscapeTerrainDetailCompression(int compression);
	static int getLandscapeTerrainDetailCompression();
	static void setLandscapeTerrainGeometryHoles(bool holes);
	static bool isLandscapeTerrainGeometryHoles();
	static void setLandscapeTerrainGeometryPolygonSize(float size);
	static float getLandscapeTerrainGeometryPolygonSize();
	static void setLandscapeTerrainGeometryProgression(float progression);
	static float getLandscapeTerrainGeometryProgression();
	static void setLandscapeTerrainGeometrySubpixelReduction(float reduction);
	static float getLandscapeTerrainGeometrySubpixelReduction();
	static void setLandscapeTerrainGeometryDetailMaxHeight(float height);
	static float getLandscapeTerrainGeometryDetailMaxHeight();
	static void setLandscapeTerrainCullingFrustumAggressive(bool aggressive);
	static bool isLandscapeTerrainCullingFrustumAggressive();
	static void setLandscapeTerrainCullingObliqueFrustum(float frustum);
	static float getLandscapeTerrainCullingObliqueFrustum();
	static void setLandscapeTerrainCullingByDepth(bool depth);
	static bool isLandscapeTerrainCullingByDepth();
	static void setLandscapeTerrainCullingDepthResolution(int resolution);
	static int getLandscapeTerrainCullingDepthResolution();
	static void setLandscapeTerrainCullingPatchResolutionGPU(int landscapeterraincullingpatchresolutiongpu);
	static int getLandscapeTerrainCullingPatchResolutionGPU();
	static void setLandscapeTerrainCullingPatchResolutionCPU(int landscapeterraincullingpatchresolutioncpu);
	static int getLandscapeTerrainCullingPatchResolutionCPU();
	static void setLandscapeTerrainCullingPatchBatching(int batching);
	static int getLandscapeTerrainCullingPatchBatching();
	static void setLandscapeTerrainCullingPaddingTriangles(float triangles);
	static float getLandscapeTerrainCullingPaddingTriangles();
	static void setLandscapeTerrainCullingPaddingPatchGPU(float landscapeterraincullingpaddingpatchgpu);
	static float getLandscapeTerrainCullingPaddingPatchGPU();
	static void setLandscapeTerrainCullingPaddingPatchCPU(float landscapeterraincullingpaddingpatchcpu);
	static float getLandscapeTerrainCullingPaddingPatchCPU();
	static void setLandscapeTerrainCullingMap(float map);
	static float getLandscapeTerrainCullingMap();
	static void setLandscapeTerrainMaskDithering(float dithering);
	static float getLandscapeTerrainMaskDithering();
	static void setLandscapeCacheCPUSize(int size);
	static int getLandscapeCacheCPUSize();
	static void setLandscapeCacheCPUPrefetchRadius(float radius);
	static float getLandscapeCacheCPUPrefetchRadius();
	static void setLandscapeCacheGPUSize(int size);
	static int getLandscapeCacheGPUSize();
	static void setLandscapeCacheGPULifeTime(int time);
	static int getLandscapeCacheGPULifeTime();
	static void setLandscapeOperationsPerFrame(int frame);
	static int getLandscapeOperationsPerFrame();
	static void setTerrainGlobalTriplanar(bool triplanar);
	static bool isTerrainGlobalTriplanar();
	static void setTerrainGlobalDisplacement(bool displacement);
	static bool isTerrainGlobalDisplacement();
	static void setTerrainGlobalDisplacementNormal(bool normal);
	static bool isTerrainGlobalDisplacementNormal();
	static void setTerrainGlobalAnisotropy(int anisotropy);
	static int getTerrainGlobalAnisotropy();
	static void setTerrainGlobalHoles(bool holes);
	static bool isTerrainGlobalHoles();
	static void setWaterGeometryPreset(int preset);
	static int getWaterGeometryPreset();
	static int getWaterGeometryPresetNumNames();
	static const char *getWaterGeometryPresetName(int num);
	static void setWaterVisibleDistance(float distance);
	static float getWaterVisibleDistance();
	static void setWaterGeometryPolygonSize(float size);
	static float getWaterGeometryPolygonSize();
	static void setWaterGeometryProgression(float progression);
	static float getWaterGeometryProgression();
	static void setWaterGeometryFadeLods(float lods);
	static float getWaterGeometryFadeLods();
	static void setWaterGeometrySubpixelReduction(float reduction);
	static float getWaterGeometrySubpixelReduction();
	static void setWaterCullingAggressive(bool aggressive);
	static bool isWaterCullingAggressive();
	static void setWaterCullingFrustumPadding(float padding);
	static float getWaterCullingFrustumPadding();
	static void setWaterCullingObliqueFrustum(float frustum);
	static float getWaterCullingObliqueFrustum();
	static void setWaterEnabled(bool enabled);
	static bool isWaterEnabled();
	static void setWaterSSR(bool waterssr);
	static bool isWaterSSR();
	static void setWaterSSRIncreasedAccuracy(bool accuracy);
	static bool isWaterSSRIncreasedAccuracy();
	static void setWaterShorelineWetness(bool wetness);
	static bool isWaterShorelineWetness();
	static void setWaterShafts(bool shafts);
	static bool isWaterShafts();
	static void setWaterOpacityDepth(bool depth);
	static bool isWaterOpacityDepth();
	static void setWaterEnvironmentProbes(bool probes);
	static bool isWaterEnvironmentProbes();
	static void setWaterPlanarProbes(bool probes);
	static bool isWaterPlanarProbes();
	static void setWaterVoxelProbes(bool probes);
	static bool isWaterVoxelProbes();
	static void setWaterLights(bool lights);
	static bool isWaterLights();
	static void setWaterSSRQuality(int quality);
	static int getWaterSSRQuality();
	static void setWaterRefractionQuality(int quality);
	static int getWaterRefractionQuality();
	static void setWaterWaterlineAccuracy(int accuracy);
	static int getWaterWaterlineAccuracy();
	static void setWaterAnisotropy(int anisotropy);
	static int getWaterAnisotropy();
	static void setCloudsEnabled(bool enabled);
	static bool isCloudsEnabled();
	static void setCloudsMode(int mode);
	static int getCloudsMode();
	static void setCloudsPanoramaResolution(int resolution);
	static int getCloudsPanoramaResolution();
	static void setCloudsPanoramaReuse(bool reuse);
	static bool isCloudsPanoramaReuse();
	static void setCloudsQualityPreset(int preset);
	static int getCloudsQualityPreset();
	static int getCloudsQualityPresetNumNames();
	static const char *getCloudsQualityPresetName(int num);
	static void setCloudsGroundShadows(bool shadows);
	static bool isCloudsGroundShadows();
	static void setCloudsTransparentOrder(int order);
	static int getCloudsTransparentOrder();
	static void setCloudsAccurateLayersSorting(bool sorting);
	static bool isCloudsAccurateLayersSorting();
	static void setCloudsLightingQuality(int quality);
	static int getCloudsLightingQuality();
	static void setCloudsSamplingQuality(int quality);
	static int getCloudsSamplingQuality();
	static void setCloudsLightingTraceLength(float length);
	static float getCloudsLightingTraceLength();
	static void setCloudsLightingConeRadius(float radius);
	static float getCloudsLightingConeRadius();
	static void setCloudsLightingSamplesDistribution(float distribution);
	static float getCloudsLightingSamplesDistribution();
	static void setCloudsDynamicCoverageArea(float area);
	static float getCloudsDynamicCoverageArea();
	static void setCloudsDynamicCoverageResolution(int resolution);
	static int getCloudsDynamicCoverageResolution();
	static void setCloudsInterleavedRendering(int rendering);
	static int getCloudsInterleavedRendering();
	static void setCloudsDownsamplingRendering(int rendering);
	static int getCloudsDownsamplingRendering();
	static void setCloudsDepthBasedReconstruction(bool reconstruction);
	static bool isCloudsDepthBasedReconstruction();
	static void setCloudsDepthBasedReconstructionThreshold(float threshold);
	static float getCloudsDepthBasedReconstructionThreshold();
	static void setCloudsInterleavedRenderingTemporal(bool temporal);
	static bool isCloudsInterleavedRenderingTemporal();
	static void setCloudsSamplesCount(int count);
	static int getCloudsSamplesCount();
	static void setCloudDistortionTexture(int texture);
	static int getCloudDistortionTexture();
	static void setCloudsSoftIntersection(float intersection);
	static float getCloudsSoftIntersection();
	static void setCloudsNoiseStep(float step);
	static float getCloudsNoiseStep();
	static void setCloudsNoiseIterations(float iterations);
	static float getCloudsNoiseIterations();
	static void setCloudsNoiseLighting(float lighting);
	static float getCloudsNoiseLighting();
	static void setCloudsNoiseStepSkip(float skip);
	static float getCloudsNoiseStepSkip();
	static void setCloudsStepAccuracy(float accuracy);
	static float getCloudsStepAccuracy();
	static void setCloudsRounded(bool rounded);
	static bool isCloudsRounded();
	static void setCloudsRoundedPlanetRadius(float radius);
	static float getCloudsRoundedPlanetRadius();
	static void setClouds3dTextureHorizontalResolution(int resolution);
	static int getClouds3dTextureHorizontalResolution();
	static void setClouds3dTextureVerticalResolution(int resolution);
	static int getClouds3dTextureVerticalResolution();
	static void setCloudsFarClipping(bool clipping);
	static bool isCloudsFarClipping();
	static void setTessellationDensityMultiplier(float multiplier);
	static float getTessellationDensityMultiplier();
	static void setTessellationShadowDensityMultiplier(float multiplier);
	static float getTessellationShadowDensityMultiplier();
	static void setTessellationDistanceMultiplier(float multiplier);
	static float getTessellationDistanceMultiplier();
	static void setFieldHeightResolution(int resolution);
	static int getFieldHeightResolution();
	static void setFieldPrecision(bool precision);
	static bool isFieldPrecision();
	static void setFieldShorelineResolution(int resolution);
	static int getFieldShorelineResolution();
	static void setScreenSpaceEffects(bool effects);
	static bool isScreenSpaceEffects();
	static void setTransparentEnabled(bool enabled);
	static bool isTransparentEnabled();
	static void setTransparentAmbient(bool ambient);
	static bool isTransparentAmbient();
	static void setTransparentLight(bool light);
	static bool isTransparentLight();
	static void setTransparentDeferred(bool deferred);
	static bool isTransparentDeferred();
	static void setTransparentMultipleEnvProbes(bool probes);
	static bool isTransparentMultipleEnvProbes();
	static void setShowFieldMask(bool mask);
	static bool isShowFieldMask();
	static void setShowFieldMaskBits(int bits);
	static int getShowFieldMaskBits();
	static void setShowShadowMask(bool mask);
	static bool isShowShadowMask();
	static void setShowShadowMaskBits(int bits);
	static int getShowShadowMaskBits();
	static void setShowObstacleMask(bool mask);
	static bool isShowObstacleMask();
	static void setShowObstacleMaskBits(int bits);
	static int getShowObstacleMaskBits();
	static void setShowMaterialMask(bool mask);
	static bool isShowMaterialMask();
	static void setShowMaterialMaskBits(int bits);
	static int getShowMaterialMaskBits();
	static void setShowViewportMask(bool mask);
	static bool isShowViewportMask();
	static void setShowViewportMaskBits(int bits);
	static int getShowViewportMaskBits();
	static void setShowPhysicalMask(bool mask);
	static bool isShowPhysicalMask();
	static void setShowPhysicalMaskBits(int bits);
	static int getShowPhysicalMaskBits();
	static void setShowCollisionMask(bool mask);
	static bool isShowCollisionMask();
	static void setShowCollisionMaskBits(int bits);
	static int getShowCollisionMaskBits();
	static void setShowNavigationMask(bool mask);
	static bool isShowNavigationMask();
	static void setShowNavigationMaskBits(int bits);
	static int getShowNavigationMaskBits();
	static void setShowIntersectionMask(bool mask);
	static bool isShowIntersectionMask();
	static void setShowIntersectionMaskBits(int bits);
	static int getShowIntersectionMaskBits();
	static void setShowSoundReverbMask(bool mask);
	static bool isShowSoundReverbMask();
	static void setShowSoundReverbMaskBits(int bits);
	static int getShowSoundReverbMaskBits();
	static void setShowSoundSourceMask(bool mask);
	static bool isShowSoundSourceMask();
	static void setShowSoundSourceMaskBits(int bits);
	static int getShowSoundSourceMaskBits();
	static void setShowSoundOcclusionMask(bool mask);
	static bool isShowSoundOcclusionMask();
	static void setShowSoundOcclusionMaskBits(int bits);
	static int getShowSoundOcclusionMaskBits();
	static void setShowPhysicalExclusionMask(bool mask);
	static bool isShowPhysicalExclusionMask();
	static void setShowPhysicalExclusionMaskBits(int bits);
	static int getShowPhysicalExclusionMaskBits();
	static void setShowPhysicsIntersectionMask(bool mask);
	static bool isShowPhysicsIntersectionMask();
	static void setShowPhysicsIntersectionMaskBits(int bits);
	static int getShowPhysicsIntersectionMaskBits();
	static void setShowQueries(bool queries);
	static bool isShowQueries();
	static void setShowDecals(bool decals);
	static bool isShowDecals();
	static void setShowScissors(bool scissors);
	static bool isShowScissors();
	static void setShowLightmapChecker(bool checker);
	static bool isShowLightmapChecker();
	static void setShowOccluder(bool occluder);
	static bool isShowOccluder();
	static void setShowCascades(bool cascades);
	static bool isShowCascades();
	static void setShowLightingMode(Render::SHOW_LIGHTING_MODE mode);
	static Render::SHOW_LIGHTING_MODE getShowLightingMode();
	static void setShowVisualizerDistance(float distance);
	static float getShowVisualizerDistance();
	static void setShowWorldShadowCasters(bool casters);
	static bool isShowWorldShadowCasters();
	static void setShowAlphaTest(bool test);
	static bool isShowAlphaTest();
	static void setShowEmission(bool emission);
	static bool isShowEmission();
	static void setShowMeshStatics(bool statics);
	static bool isShowMeshStatics();
	static void setShowMeshDynamics(bool dynamics);
	static bool isShowMeshDynamics();
	static void setShowComplexShadowShader(bool shader);
	static bool isShowComplexShadowShader();
	static void setShowSurfaceCustomTextureNotAvailable(bool available);
	static bool isShowSurfaceCustomTextureNotAvailable();
	static void setShowSurfaceCustomTextureNotUsed(bool used);
	static bool isShowSurfaceCustomTextureNotUsed();
	static void setShowSurfaceCustomTexture(bool texture);
	static bool isShowSurfaceCustomTexture();
	static void setShowPhysicsIntersection(bool intersection);
	static bool isShowPhysicsIntersection();
	static void setShowIntersection(bool intersection);
	static bool isShowIntersection();
	static void setShowManualMaterials(bool materials);
	static bool isShowManualMaterials();
	static void setShowNonManualMaterials(bool materials);
	static bool isShowNonManualMaterials();
	static void setShowClusters(bool clusters);
	static bool isShowClusters();
	static void setShowImmovable(Render::SHOW_IMMOVABLE immovable);
	static Render::SHOW_IMMOVABLE getShowImmovable();
	static void setShowDynamic(bool dynamic);
	static bool isShowDynamic();
	static void setShowTransparent(bool transparent);
	static bool isShowTransparent();
	static void setShowAmbient(bool ambient);
	static bool isShowAmbient();
	static void setShowGeodeticPivot(bool pivot);
	static bool isShowGeodeticPivot();
	static void setShowLandscapeMask(int mask);
	static int getShowLandscapeMask();
	static void setShowLandscapeAlbedo(bool albedo);
	static bool isShowLandscapeAlbedo();
	static void setShowLandscapeTerrainVTStreaming(bool streaming);
	static bool isShowLandscapeTerrainVTStreaming();
	static void setShowVoxelProbeVisualizer(bool visualizer);
	static bool isShowVoxelProbeVisualizer();
	static void setShowVoxelProbeVisualizerGridSize(int size);
	static int getShowVoxelProbeVisualizerGridSize();
	static void setShowVoxelProbeVisualizerSphereScale(float scale);
	static float getShowVoxelProbeVisualizerSphereScale();
	static void setShowNodesInteractionTrigger(bool trigger);
	static bool isShowNodesInteractionTrigger();
	static void setShowNodesInteractionClutter(bool clutter);
	static bool isShowNodesInteractionClutter();
	static void setShowNodesInteractionGrass(bool grass);
	static bool isShowNodesInteractionGrass();
	static void setShowTextures(int textures);
	static int getShowTextures();
	static void setShowTexturesOffset(int offset);
	static int getShowTexturesOffset();
	static void setShowTexturesNumber(int number);
	static int getShowTexturesNumber();
	static void setShowTriangles(int triangles);
	static int getShowTriangles();
	static void setShowVertexColor(Render::SHOW_VERTEX_COLOR color);
	static Render::SHOW_VERTEX_COLOR getShowVertexColor();
	static void setShowTextureResolution(Render::SHOW_TEXTURE_RESOLUTION resolution);
	static Render::SHOW_TEXTURE_RESOLUTION getShowTextureResolution();
	static void setShowTextureResolutionUVMode(Render::SHOW_TEXTURE_RESOLUTION_UV mode);
	static Render::SHOW_TEXTURE_RESOLUTION_UV getShowTextureResolutionUVMode();
	static void setShowTextureResolutionStreamingAccountingMode(Render::SHOW_TEXTURE_RESOLUTION_STREAMING_ACCOUNTING mode);
	static Render::SHOW_TEXTURE_RESOLUTION_STREAMING_ACCOUNTING getShowTextureResolutionStreamingAccountingMode();
	static void setShowTextureResolutionBlend(float blend);
	static float getShowTextureResolutionBlend();
	static int getHDRTextureFormat();

	enum TEXTURE_ACCESSORY
	{
		TEXTURE_ACCESSORY_NONE = 0,
		TEXTURE_ACCESSORY_GBUFFER,
		TEXTURE_ACCESSORY_WBUFFER,
		TEXTURE_ACCESSORY_RENDER,
		TEXTURE_ACCESSORY_OCCLUDERS,
		TEXTURE_ACCESSORY_EXTERNAL,
	};

	enum TEXTURE_LIFETIME
	{
		TEXTURE_LIFETIME_FRAME_VIEWPORT = 0,
		TEXTURE_LIFETIME_FRAME_APPLICATION,
		TEXTURE_LIFETIME_APPLICATION,
	};
	static Ptr<Texture> getTemporaryTexture(int width, int height, int depth, int format, int flags, int type, const char *name = 0, Render::TEXTURE_ACCESSORY accessory = Render::TEXTURE_ACCESSORY_NONE, Render::TEXTURE_LIFETIME lifetime = Render::TEXTURE_LIFETIME_FRAME_VIEWPORT, bool auto_release = false);
	static Ptr<Texture> getTemporaryTexture(const Ptr<Texture> &texture, const char *name = 0, Render::TEXTURE_ACCESSORY accessory = Render::TEXTURE_ACCESSORY_NONE, Render::TEXTURE_LIFETIME lifetime = Render::TEXTURE_LIFETIME_FRAME_VIEWPORT, bool auto_release = false);
	static Ptr<Texture> getTemporaryTexture(const Ptr<Image> &image, int flags = -1, const char *name = 0, Render::TEXTURE_ACCESSORY accessory = Render::TEXTURE_ACCESSORY_NONE, Render::TEXTURE_LIFETIME lifetime = Render::TEXTURE_LIFETIME_FRAME_VIEWPORT, bool auto_release = false);
	static Ptr<Texture> getTemporaryTexture2D(int width, int height, int format, int flags = -1, const char *name = 0, Render::TEXTURE_ACCESSORY accessory = Render::TEXTURE_ACCESSORY_NONE, Render::TEXTURE_LIFETIME lifetime = Render::TEXTURE_LIFETIME_FRAME_VIEWPORT, bool auto_release = false);
	static Ptr<Texture> getTemporaryTexture2DArray(int width, int height, int depth, int format, int flags = -1, const char *name = 0, Render::TEXTURE_ACCESSORY accessory = Render::TEXTURE_ACCESSORY_NONE, Render::TEXTURE_LIFETIME lifetime = Render::TEXTURE_LIFETIME_FRAME_VIEWPORT, bool auto_release = false);
	static Ptr<Texture> getTemporaryTexture3D(int width, int height, int depth, int format, int flags = -1, const char *name = 0, Render::TEXTURE_ACCESSORY accessory = Render::TEXTURE_ACCESSORY_NONE, Render::TEXTURE_LIFETIME lifetime = Render::TEXTURE_LIFETIME_FRAME_VIEWPORT, bool auto_release = false);
	static Ptr<Texture> getTemporaryTextureCube(int width, int height, int format, int flags = -1, const char *name = 0, Render::TEXTURE_ACCESSORY accessory = Render::TEXTURE_ACCESSORY_NONE, Render::TEXTURE_LIFETIME lifetime = Render::TEXTURE_LIFETIME_FRAME_VIEWPORT, bool auto_release = false);
	static Ptr<Texture> getTemporaryTextureCubeArray(int width, int height, int depth, int format, int flags = -1, const char *name = 0, Render::TEXTURE_ACCESSORY accessory = Render::TEXTURE_ACCESSORY_NONE, Render::TEXTURE_LIFETIME lifetime = Render::TEXTURE_LIFETIME_FRAME_VIEWPORT, bool auto_release = false);
	static Ptr<Texture> getTemporaryOldTexture(const Ptr<Material> &mat, int texture_id, int width, int height, int depth, int format, int flags, int type, const char *name = 0, Render::TEXTURE_ACCESSORY accessory = Render::TEXTURE_ACCESSORY_NONE);
	static Ptr<Texture> getTemporaryOldTexture(const Ptr<Material> &mat, int texture_id, const Ptr<Texture> &texture, const char *name = 0, Render::TEXTURE_ACCESSORY accessory = Render::TEXTURE_ACCESSORY_NONE);
	static Ptr<Texture> getTemporaryOldTexture(const Ptr<Material> &mat, int texture_id, const Ptr<Image> &image, int flags = -1, const char *name = 0, Render::TEXTURE_ACCESSORY accessory = Render::TEXTURE_ACCESSORY_NONE);
	static Ptr<Texture> getTemporaryOldTexture2D(const Ptr<Material> &mat, int texture_id, int width, int height, int format, int flags = -1, const char *name = 0, Render::TEXTURE_ACCESSORY accessory = Render::TEXTURE_ACCESSORY_NONE);
	static Ptr<Texture> getTemporaryOldTexture2DArray(const Ptr<Material> &mat, int texture_id, int width, int height, int depth, int format, int flags = -1, const char *name = 0, Render::TEXTURE_ACCESSORY accessory = Render::TEXTURE_ACCESSORY_NONE);
	static Ptr<Texture> getTemporaryOldTexture3D(const Ptr<Material> &mat, int texture_id, int width, int height, int depth, int format, int flags = -1, const char *name = 0, Render::TEXTURE_ACCESSORY accessory = Render::TEXTURE_ACCESSORY_NONE);
	static Ptr<Texture> getTemporaryOldTextureCube(const Ptr<Material> &mat, int texture_id, int width, int height, int format, int flags = -1, const char *name = 0, Render::TEXTURE_ACCESSORY accessory = Render::TEXTURE_ACCESSORY_NONE);
	static Ptr<Texture> getTemporaryOldTextureCubeArray(const Ptr<Material> &mat, int texture_id, int width, int height, int depth, int format, int flags = -1, const char *name = 0, Render::TEXTURE_ACCESSORY accessory = Render::TEXTURE_ACCESSORY_NONE);
	static void releaseTemporaryTexture(const Ptr<Texture> &texture);
	static void releaseTemporaryTextures(const Vector<Ptr<Texture>> &textures);
	static bool isTemporaryTexture(const Ptr<Texture> &texture);
	static bool isTemporaryOldTexture(const Ptr<Texture> &texture);
	static Ptr<RenderTarget> getTemporaryRenderTarget();
	static void releaseTemporaryRenderTarget(const Ptr<RenderTarget> &render_target);
	static Ptr<Texture> getBlack2DTexture();
	static Ptr<Texture> getBlack2DUIntTexture();
	static Ptr<Texture> getBlack2DArrayTexture();
	static Ptr<Texture> getBlackCubeTexture();
	static Ptr<Texture> getBlack3DTexture();
	static Ptr<Texture> getWhite2DTexture();
	static Ptr<Texture> getWhite2DUIntTexture();
	static Ptr<Texture> getWhite2DArrayTexture();
	static Ptr<Texture> getWhiteCubeTexture();
	static Ptr<Texture> getWhite3DTexture();
	static Ptr<Texture> getGray2DTexture();
	static Ptr<Texture> getGray2DUIntTexture();
	static Ptr<Texture> getGray2DArrayTexture();
	static Ptr<Texture> getGrayCubeTexture();
	static Ptr<Texture> getGray3DTexture();
	static int getNumDecals();
	static int getNumDips();
	static int getNumLights();
	static int getNumMaterials();
	static int getNumPrimitives();
	static int getNumReflections();
	static long long getNumShaders();
	static int getNumShadows();
	static int getNumSurfaces();
	static int getNumTriangles();
	static bool loadSettings(const char *file, bool clear = false);
	static bool saveSettings(const char *file);
	static bool loadWorld(const Ptr<Xml> &xml);
	static bool saveWorld(const Ptr<Xml> &xml);
	static bool restoreState(const Ptr<Stream> &stream);
	static bool saveState(const Ptr<Stream> &stream);
	static Ptr<Texture> getCacheTexture(const UGUID &guid, bool forced = false);
	static void * getD3D11Factory();
	static void * getD3D11Device();
	static void * getD3D11Context();
	static void reloadResource(const char *path);
	static void reloadResource(const Vector<String> &paths);
};

//////////////////////////////////////////////////////////////////////////

class UNIGINE_API RenderState
{
public:
	static bool isInitialized();

	enum
	{
		BUFFER_NONE = 0,
		BUFFER_RED = 1 << 0,
		BUFFER_GREEN = 1 << 1,
		BUFFER_BLUE = 1 << 2,
		BUFFER_ALPHA = 1 << 3,
		BUFFER_DEPTH = 1 << 4,
		BUFFER_STENCIL = 1 << 5,
		BUFFER_COLOR = (BUFFER_RED | BUFFER_GREEN | BUFFER_BLUE | BUFFER_ALPHA),
		BUFFER_DEPTH_STENCIL = (BUFFER_DEPTH | BUFFER_STENCIL),
		BUFFER_ALL = (BUFFER_COLOR | BUFFER_DEPTH_STENCIL),
	};

	enum
	{
		DEPTH_NONE = 0,
		DEPTH_EQUAL,
		DEPTH_LEQUAL,
		DEPTH_GEQUAL,
		DEPTH_ALWAYS,
		DEPTH_NOT_EQUAL,
	};

	enum
	{
		STENCIL_NONE = 0,
		STENCIL_LESS,
		STENCIL_EQUAL,
		STENCIL_LESS_EQUAL,
		STENCIL_GREATER,
		STENCIL_NOT_EQUAL,
		STENCIL_GREATER_EQUAL,
		STENCIL_ALWAYS,
	};

	enum
	{
		STENCIL_KEEP = 0,
		STENCIL_INCR,
		STENCIL_DECR,
		STENCIL_REPLACE,
	};

	enum
	{
		BLEND_NONE = 0,
		BLEND_ZERO,
		BLEND_ONE,
		BLEND_SRC_COLOR,
		BLEND_ONE_MINUS_SRC_COLOR,
		BLEND_SRC_ALPHA,
		BLEND_ONE_MINUS_SRC_ALPHA,
		BLEND_DEST_COLOR,
		BLEND_ONE_MINUS_DEST_COLOR,
		BLEND_DEST_ALPHA,
		BLEND_ONE_MINUS_DEST_ALPHA,
		BLEND_SRC1_COLOR,
		BLEND_ONE_MINUS_SRC1_COLOR,
		BLEND_SRC1_ALPHA,
		BLEND_ONE_MINUS_SRC1_ALPHA,
	};

	enum
	{
		BLEND_OP_ADD = 0,
		BLEND_OP_SUBTRACT,
		BLEND_OP_REVERSE_SUBTRACT,
		BLEND_OP_MIN,
		BLEND_OP_MAX,
	};

	enum
	{
		FRONT_CCW = 0,
		FRONT_CW,
		FRONT_INVERT,
	};

	enum
	{
		CULL_NONE = 0,
		CULL_BACK,
		CULL_FRONT,
	};

	enum
	{
		FILL_SOLID = 0,
		FILL_WIREFRAME,
	};

	enum
	{
		BIND_ALL = 0,
		BIND_FRAGMENT,
	};
	static void clearStates(bool clear_all = true);
	static void clearStructuredBuffers();
	static void clearStructuredBuffer(const Ptr<StructuredBuffer> &buffer);
	static void clearTextures();
	static void clearTexture(const Ptr<Texture> &texture);
	static void clearBuffer(int buffer, const Math::vec4 &color, float depth = 0.0f, int stencil = 0);
	static void dispatch(int group_threads_x, int group_threads_y, int group_threads_z);
	static void saveState();
	static void restoreState();
	static void flushStates();
	static void flushRender();
	static void setViewport(int x, int y, int width, int height);
	static int getWidth();
	static int getHeight();
	static int getCoordX();
	static int getCoordY();
	static void setScissorTest(float x, float y, float width, float height);
	static void setScissorTest(const Math::vec4 &rectangle);
	static void setScissorTest(const Math::ivec4 &rectangle);
	static int getScissorTest();
	static void setBufferMask(int num, int mask);
	static int getBufferMask(int num);
	static void setDepthFunc(int func);
	static int getDepthFunc();
	static void setStencilFunc(int func);
	static int getStencilFunc();
	static void setStencilPass(int pass);
	static int getStencilPass();
	static void setStencilRef(int ref);
	static int getStencilRef();
	static void setBlendFunc(int src, int dest, int blend_op = 0);
	static void setBlendSrcFunc(int func);
	static int getBlendSrcFunc();
	static void setBlendDestFunc(int func);
	static int getBlendDestFunc();
	static void setBlendOperation(int operation);
	static int getBlendOperation();
	static void setBlendFuncBuffer(int num, int src, int dest, int blend_op = 0);
	static int getBlendSrcFuncBuffer(int num);
	static int getBlendDestFuncBuffer(int num);
	static int getBlendOperationBuffer(int num);
	static void setPolygonFront(int front);
	static int getPolygonFront();
	static void setPolygonCull(int cull);
	static int getPolygonCull();
	static void setPolygonFill(int fill);
	static int getPolygonFill();
	static void setPolygonOffset(float bias, float offset);
	static void setPolygonBias(float bias);
	static float getPolygonBias();
	static void setPolygonSlope(float slope);
	static float getPolygonSlope();
	static void setAnisotropy(int anisotropy);
	static int getAnisotropy();
	static void setShader(const Ptr<Shader> &shader);
	static Ptr<Shader> getShader();
	static void setMaterial(const Ptr<Material> &material);
	static Ptr<Material> getMaterial();
	static void setMaterial(Render::PASS pass, const Ptr<Material> &material);
	static void setTexture(int binding, int num, const Ptr<Texture> &texture);
	static void setTexture(int binding, int num, const Ptr<Texture> &texture, int sampler_flags);
	static void setStructuredBuffer(int num, const Ptr<StructuredBuffer> &buffer);
	static Ptr<Texture> getTexture(int num);
	static Ptr<Texture> getScreenDepthTexture();
	static Ptr<Texture> getScreenColorTexture();
};

//////////////////////////////////////////////////////////////////////////

class UNIGINE_API Renderer
{
public:
	static bool isInitialized();

	enum
	{
		RENDER_STEREO_DEFAULT = 0,
		RENDER_STEREO_HORIZONTAL,
		RENDER_STEREO_VERTICAL,
	};

	enum RENDER_STEREO_EYE
	{
		RENDER_STEREO_EYE_NONE = 0,
		RENDER_STEREO_EYE_LEFT,
		RENDER_STEREO_EYE_RIGHT,
		RENDER_STEREO_EYE_LEFT_FOCUS,
		RENDER_STEREO_EYE_RIGHT_FOCUS,
	};

	struct CBufferCamera
	{
		Math::mat4 camera_projection;
		Math::mat4 camera_iprojection;

		Math::vec4 oblique_frustum_plane;
		int is_oblique_frustum;

		Math::mat4 projection;
		Math::mat4 iprojection;

		Math::mat4 projection_screen;
		Math::mat4 iprojection_screen;

		Math::mat4 imodelview;
		Math::mat4 old_imodelview;
		Math::mat4 old_imodelview_delta;

		Math::mat4 modelview;
		Math::mat4 old_modelview;

		Math::vec3 camera_offset;
		Math::vec3 camera_position;
		Math::vec3 camera_direction;

		Math::vec3 projection_row_0;
		Math::vec3 projection_row_1;
		Math::vec3 projection_row_2;

		Math::vec4 modelview_projection_x;
		Math::vec4 modelview_projection_y;
		Math::vec4 modelview_projection_w;

		Math::vec4 modelview_projection_old_x;
		Math::vec4 modelview_projection_old_y;
		Math::vec4 modelview_projection_old_w;

		float camera_fov;
		int shadow_cascade_target;
	};


	struct CBufferScattering
	{
		Math::vec3 scattering_sun_dir;
		Math::vec3 scattering_moon_dir;

		float environment_ambient_intensity;
		float environment_reflection_intensity;
		float environment_sky_intensity;

		Math::vec4 haze_color;
		float haze_max_distance;
		float haze_density;

		float haze_physical_start_height;
		float haze_physical_density;
		float haze_physical_falloff;
		float haze_physical_zero_visibility_height;

		float haze_physical_screen_space_global_illumination;
		float haze_physical_ambient_light_intensity;
		float haze_physical_ambient_color_saturation;
		float haze_physical_sun_light_intensity;
		float haze_physical_sun_color_saturation;

		float haze_scattering_mie_intensity;
		float haze_scattering_mie_front_side_intensity;
		float haze_scattering_mie_fresnel_power;

		Math::vec3 sky_up;
		float sky_altitude;
		Math::mat4 sky_transform;

		Math::vec3 sun_color;
		Math::mat4 sun_rotation;
		Math::mat4 moon_rotation;
	};


	struct CBufferTonemapper
	{
		Math::vec4 filmic_curve;
		Math::vec4 filmic_white;
		float filmic_saturation_recovery;

		float aces_white_clip;
		float aces_toe;
		float aces_shoulder_angle;
		float aces_shoulder_strength;
		float aces_shoulder_length;

		float aces_with_reinhard_mix;
		float aces_with_reinhard_white_clip;
		float aces_with_reinhard_toe;
		float aces_with_reinhard_shoulder_angle;
		float aces_with_reinhard_shoulder_strength;
		float aces_with_reinhard_shoulder_length;

		float reinhard_contribution;
		float reinhard_luma_based_contribution;
	};

	static Renderer::CBufferCamera getShaderCBufferCamera();
	static Renderer::CBufferScattering getShaderCBufferScattering();
	static Renderer::CBufferTonemapper getShaderCBufferTonemapper();
	static bool hasGeodeticPivot();
	static bool isNode();
	static bool isReflection();
	static bool isShadow();
	static bool isStereo();
	static bool isStereoPeripheral();
	static void setVR(bool vr);
	static bool isVR();
	static int getViewportMask();
	static int getReflectionViewportMask();
	static int getSkipFlags();
	static int checkSkipFlags(int flags);
	static void setUseTAAOffset(bool offset);
	static bool isUseTAAOffset();
	static int getStereoMode();
	static Renderer::RENDER_STEREO_EYE getStereoCurrentEye();
	static Ptr<Viewport> getViewport();
	static void setProjection(const Math::mat4 &projection);
	static Math::mat4 getProjection();
	static void setOldProjection(const Math::mat4 &projection);
	static Math::mat4 getOldProjection();
	static Math::mat4 getProjectionWithoutTAA();
	static void setModelview(const Math::Mat4 &modelview);
	static Math::Mat4 getModelview();
	static Math::Mat4 getIModelview();
	static void setOldModelview(const Math::Mat4 &modelview);
	static Math::Mat4 getOldModelview();
	static void setCameraPosition(const Math::Vec3 &position);
	static Math::Vec3 getCameraPosition();
	static float getZNear();
	static float getZFar();
	static void setObliqueFrustumPlane(const Math::Vec4 &plane);
	static Math::Vec4 getObliqueFrustumPlane();
	static void setObliqueFrustum(bool frustum);
	static bool isObliqueFrustum();
	static bool useVelocityBuffer();
	static bool useTAA();
	static bool useShadows();
	static bool useVisualizer();
	static bool useDynamicReflections();
	static bool usePostEffects();
	static bool useOcclusionQueries();
	static bool useUpscale();
	static Ptr<Light> getCurrentLight();
	static void setOverlapEnvironmentTexture(const Ptr<Texture> &texture);
	static Ptr<Texture> getOverlapEnvironmentTexture();
	static void resetOverlapEnvironmentTexture();
	static void saveState();
	static void restoreState();
	static void setBufferMask(Render::PASS pass, const Ptr<Material> &material);
	static void setDepthFunc(Render::PASS pass, const Ptr<Material> &material);
	static void setBlendFunc(Render::PASS pass, const Ptr<Material> &material);
	static void setPolygonCull(Render::PASS pass, const Ptr<Material> &material);
	static void clearShader();
	static void clearStates();
	static void setMaterial(Render::PASS pass, const Ptr<Material> &material);
	static void setShaderParameters(Render::PASS pass, const Ptr<Shader> &shader, const Ptr<Material> &material, const Ptr<Object> &object, int surface, bool is_screen_space);
	static void setShaderParameters(Render::PASS pass, const Ptr<Shader> &shader, const Ptr<Material> &material, bool is_screen_space);
	static void setShaderParameters(Render::PASS pass, const Ptr<Shader> &shader, bool is_screen_space);
	static void setShaderParameters(Render::PASS pass, const Ptr<Material> &material, bool is_screen_space);
	static void setShaderParameters(Render::PASS pass, const Ptr<Object> &object, int surface, bool is_screen_space);
	static Vector<Ptr<Object>> getObjects();
	static int getWidth();
	static int getHeight();
	static Ptr<RenderTarget> getRenderTarget();
	static Ptr<RenderTarget> getPostRenderTarget();
	static Ptr<Texture> getTextureColor();
	static Ptr<Texture> getTextureColorOpacity();
	static Ptr<Texture> getTextureColorOld();
	static Ptr<Texture> getTextureColorOldReprojection();
	static Ptr<Texture> getTextureNormalUnpack();
	static Ptr<Texture> getTextureCurrentDepth();
	static Ptr<Texture> getTextureOpacityDepth();
	static Ptr<Texture> getTextureLinearDepth();
	static Ptr<Texture> getTextureAuxiliary();
	static Ptr<Texture> getTextureRefraction();
	static Ptr<Texture> getTextureRefractionMask();
	static Ptr<Texture> getTextureTransparentBlur();
	static Ptr<Texture> getTextureDirectLights();
	static Ptr<Texture> getTextureIndirectLights();
	static Ptr<Texture> getTextureBentNormal();
	static Ptr<Texture> getTextureSSAO();
	static Ptr<Texture> getTextureSSGI();
	static Ptr<Texture> getTextureSSR();
	static Ptr<Texture> getTextureSSShadowShafts();
	static Ptr<Texture> getTextureSSCurvature();
	static Ptr<Texture> getTextureDOFMask();
	static Ptr<Texture> getTextureAutoExposure();
	static Ptr<Texture> getTextureAutoWhiteBalance();
	static Ptr<Texture> getTextureClouds();
	static Ptr<Texture> getTextureGBufferAlbedo();
	static Ptr<Texture> getTextureGBufferShading();
	static Ptr<Texture> getTextureGBufferNormal();
	static Ptr<Texture> getTextureGBufferMaterialMask();
	static Ptr<Texture> getTextureGBufferFeatures();
	static Ptr<Texture> getTextureGBufferVelocity();
	static Ptr<Texture> createCustomTexture3D(const char *name, int width, int height, int depth, int format, int flags = 0);
	static Ptr<Texture> createCustomTexture2DArray(const char *name, int width, int height, int depth, int format, int flags = 0);
	static Ptr<Texture> createCustomTexture2D(const char *name, int width, int height, int format, int flags = 0);
	static Ptr<Texture> getCustomTexture(const char *name);
	static void renderMesh(const Ptr<MeshRender> &mesh, const Ptr<Material> &material, const char *pass_name, const Math::Mat4 &transform, const Ptr<Camera> &camera);
};

//////////////////////////////////////////////////////////////////////////

class UNIGINE_API BakeLighting
{
public:
	static bool isInitialized();

	enum LIGHTMAP_QUALITY
	{
		LIGHTMAP_QUALITY_DRAFT = 0,
		LIGHTMAP_QUALITY_LOW,
		LIGHTMAP_QUALITY_MEDIUM,
		LIGHTMAP_QUALITY_HIGH,
		LIGHTMAP_QUALITY_ULTRA,
	};
	static void bakeAll(bool voxel_probes = true, bool env_probes = true, bool shadow = true, bool lightmap = true);
	static void bake(const Vector<Ptr<LightVoxelProbe>> &voxel_lights, const Vector<Ptr<LightEnvironmentProbe>> &env_lights, const Vector<Ptr<Light>> &shadow_lights, const Vector<Ptr<ObjectMeshStatic>> &objects, const Vector<int> &surfaces);
	static void stop(bool save_results = false);
	static bool isBaking();
	static void setSamplesPerFrame(int frame);
	static int getSamplesPerFrame();
	static void setBounces(int bounces);
	static int getBounces();
	static void setVoxelSizeMultiplier(float multiplier);
	static float getVoxelSizeMultiplier();
	static void setLightmapQuality(BakeLighting::LIGHTMAP_QUALITY quality);
	static BakeLighting::LIGHTMAP_QUALITY getLightmapQuality();
	static void setLightmapViewportMask(int mask);
	static int getLightmapViewportMask();
	static void setLightmapZFar(float zfar);
	static float getLightmapZFar();
	static void setCacheDir(const char *dir);
	static const char *getCacheDir();
	static float getTimer();
	static Ptr<Light> getCurrentLight();
	static Ptr<Object> getCurrentObject();
	static int getCurrentSurface();
	static int getCurrentBounce();
	static int getProgressLight();
	static int getProgressBounce();
	static int getProgress();
	static void addReadOnlyTexture(const UGUID &guid);
	static void removeReadOnlyTexture(const UGUID &guid);
};

} // namespace Unigine
