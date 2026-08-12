# 🏷️ Convenciones de Nombres - KaraipyHare Project

**Objetivo:** Mantener consistencia y evitar confusiones en todo el proyecto.

---

## 📌 Regla General

```
[Prefijo]_[Nombre Descriptivo]_v[Versión].[Extensión]

Ejemplo: BP_Flashlight_v01.uasset
         WBP_MainMenu_v02.uasset
         Wind_Soft_Loop_v01.wav
```

---

## 🎯 Blueprints

### Prefijos estándar:

| Prefijo | Tipo | Ejemplo |
|---------|------|---------|
| `BP_` | Blueprint general | `BP_Player.uasset` |
| `WBP_` | Widget Blueprint (UI) | `WBP_HUD.uasset` |
| `ABP_` | Animation Blueprint | `ABP_PlayerRun.uasset` |
| `DT_` | Data Table | `DT_ItemDatabase.uasset` |
| `DA_` | Data Asset | `DA_LevelConfig.uasset` |
| `MA_` | Master Material | `MA_Wood.uasset` |
| `M_` | Material Instance | `M_Wood_Oak.uasset` |
| `Enum_` | Enumeration | `Enum_InteractionTypes.uasset` |
| `Struct_` | Structure | `Struct_ItemData.uasset` |

### Ejemplos completos:

```
1_Programming/Blueprints/Characters/
  ├─ BP_Player_v01.uasset
  ├─ BP_Player_v02.uasset
  └─ BP_Player_v03.uasset  (versión final)

1_Programming/Blueprints/Systems/Lighting/
  ├─ BP_Flashlight_v01.uasset
  ├─ BP_FlashlightUI_v01.uasset
  └─ BP_DynamicLighting_v01.uasset

1_Programming/Blueprints/Systems/Interaction/
  ├─ BP_Door_v01.uasset
  ├─ BP_DoorLocked_v01.uasset
  ├─ BP_KeyPickup_v01.uasset
  └─ BP_InteractionSystem_v02.uasset

1_Programming/Blueprints/UI/
  ├─ WBP_HUD_v01.uasset
  ├─ WBP_Inventory_v01.uasset
  ├─ WBP_StaminaBar_v01.uasset
  └─ WBP_MainMenu_v01.uasset
```

---

## 🎨 Modelos 3D (Assets)

### Prefijos para modelos:

| Prefijo | Categoría | Ejemplo |
|---------|-----------|---------|
| `SK_` | Skeletal Mesh (con huesos) | `SK_Player_v01.uasset` |
| `SM_` | Static Mesh (sin huesos) | `SM_Tree_Oak_v01.uasset` |
| `BS_` | Blueprint Static | `BS_Door_Wooden_v01.uasset` |

### Archivos .fbx de Blender:

```
3_Art_Assets/3D_Models/Environment/Trees/
  ├─ Tree_Oak_v01.fbx          (importado de Blender)
  ├─ Tree_Oak_v02.fbx
  └─ Source/
      └─ Tree_Oak_v01.blend    (fuente original)

3_Art_Assets/3D_Models/Interactive_Objects/Doors/
  ├─ Door_Wooden_v01.fbx
  ├─ Door_Wooden_v02.fbx
  └─ Source/
      └─ Door_Wooden_v01.blend

3_Art_Assets/3D_Models/Interactive_Objects/Keys/
  ├─ Key_Brass_v01.fbx
  └─ Source/
      └─ Key_Brass_v01.blend
```

### Convención en Unreal (después de import):

```
Content/Assets/Models/
  ├─ SM_Tree_Oak_v01
  ├─ SK_Player_v01
  ├─ SM_Door_Wooden_v01
  └─ SM_Key_Brass_v01
```

---

## 🎨 Texturas

### Prefijos de texturas:

| Sufijo | Tipo | Ejemplo |
|--------|------|---------|
| `_D` o `_Diffuse` | Mapa de color (Albedo) | `Wood_D.tga` |
| `_N` o `_Normal` | Mapa normal | `Wood_N.tga` |
| `_R` o `_Roughness` | Mapa de rugosidad | `Wood_R.tga` |
| `_M` o `_Metallic` | Mapa metálico | `Metal_M.tga` |
| `_AO` | Ambient Occlusion | `Wood_AO.tga` |

### Estructura completa:

```
3_Art_Assets/Textures/PBR/Wood/
  ├─ Wood_Oak_D.tga
  ├─ Wood_Oak_N.tga
  ├─ Wood_Oak_R.tga
  ├─ Wood_Oak_M.tga
  └─ Wood_Oak_AO.tga

3_Art_Assets/Textures/PBR/Stone/
  ├─ Stone_Brick_D.tga
  ├─ Stone_Brick_N.tga
  ├─ Stone_Brick_R.tga
  └─ Stone_Brick_AO.tga
```

---

## 🔊 Audio

### Prefijos de audio:

| Tipo | Prefijo | Ejemplo |
|------|---------|---------|
| Ambient/Loop | `Loop_` | `Loop_Wind_Soft_v01.wav` |
| Sound Effect | `SFX_` | `SFX_DoorOpen_v01.wav` |
| Música | `Music_` | `Music_MainTheme_v01.wav` |
| Voz | `VO_` | `VO_EnemyScream_v01.wav` |

### Estructura de audio:

```
3_Art_Assets/Audio/Ambient/Wind/
  ├─ Loop_Wind_Soft_v01.wav
  └─ Loop_Wind_Strong_v01.wav

3_Art_Assets/Audio/Sound_Effects/Footsteps/
  ├─ SFX_Footstep_Grass_v01.wav
  ├─ SFX_Footstep_Wood_v01.wav
  └─ SFX_Footstep_Stone_v01.wav

3_Art_Assets/Audio/Sound_Effects/Interactions/
  ├─ SFX_DoorOpen_v01.wav
  ├─ SFX_DoorClose_v01.wav
  ├─ SFX_KeyPickup_v01.wav
  └─ SFX_LanternClick_v01.wav

3_Art_Assets/Audio/Sound_Effects/Ambience/
  ├─ SFX_BranchBreak_v01.wav
  ├─ SFX_Whispers_v01.wav
  └─ SFX_Fear_Ambience_v01.wav
```

---

## 🗂️ Carpetas

### Convenciones de carpetas:

| Tipo | Formato | Ejemplo |
|------|---------|---------|
| Categorías principales | `camelCase` | `/Characters/`, `/Systems/` |
| Sub-categorías | `camelCase` | `/Lighting/`, `/Interaction/` |
| Específicas | `snake_case` | `/sound_effects/`, `/terrain_materials/` |

### Ejemplos:

```
Correcto:
  1_Programming/Blueprints/Characters/
  1_Programming/Blueprints/Systems/Lighting/
  3_Art_Assets/3D_Models/Environment/

Incorrecto:
  1_Programming/blueprints/characters/ (minúsculas incorrectas)
  1_Programming/Blueprints/SYSTEMS/Lighting/ (mayúsculas)
  3_Art_Assets/3d_models/ (número con minúscula)
```

---

## 📝 Documentos

### Tipo de documento | Formato | Ejemplo

| Tipo | Formato | Ejemplo |
|------|---------|---------|
| Guía/Estándar | `SCREAMING_SNAKE_CASE` | `BLUEPRINT_STANDARDS.md` |
| Información general | `PascalCase` | `Project_Overview.md` |
| Log/Notas | `camelCase` | `Implementation_Log.md` |
| Configuración | `snake_case` | `quality_settings.ini` |

### Ejemplos:

```
1_Programming/Documentation/
  ├─ BLUEPRINT_STANDARDS.md
  ├─ IMPLEMENTATION_LOG.md
  ├─ API_REFERENCE.md
  └─ Known_Issues.md

2_Level_Design/Lighting/
  ├─ LIGHTING_GUIDE.md
  └─ Atmospheric_Effects.md

3_Art_Assets/Documentation/
  ├─ ASSET_INVENTORY.md
  ├─ IMPORT_GUIDELINES.md
  └─ 3D_STANDARDS.md

Shared_Resources/Documentation/
  ├─ PROJECT_OVERVIEW.md
  ├─ TEAM_ROLES.md
  ├─ GIT_WORKFLOW.md
  └─ CONFLICT_RESOLUTION.md
```

---

## 🔢 Versionado

### Sistema de versiones:

```
v01 → v02 → v03 → ... → v98 → v99 (FINAL)

Reglas:
- Siempre 2 dígitos (v01, no v1)
- Incrementa cuando hay cambios significativos
- v99 indica versión "release" o final
- Nunca sobrescribas, siempre crea nueva versión
```

### Ejemplos de cambios que merecen nueva versión:

```
BP_Player_v01.uasset    → Versión inicial
BP_Player_v02.uasset    → Agregado sistema de stamina
BP_Player_v03.uasset    → Arreglado bug de movimiento
BP_Player_v04.uasset    → Optimización de rendimiento
BP_Player_v99.uasset    → VERSIÓN FINAL PARA RELEASE

Si lo necesitas en una rama de mantenimiento:
BP_Player_v99_hotfix.uasset  (en rama hotfix/)
```

---

## ⚠️ Anti-Patrones (NO HACER)

```
❌ BP_new_blueprint.uasset          (no descriptivo)
❌ Flashlight.uasset                (sin prefijo ni versión)
❌ BP_Flashlight.uasset             (sin versión)
❌ BP_Flashlight_FINAL.uasset       (usar v99, no "FINAL")
❌ BP_Flashlight_2.uasset           (v02, no _2)
❌ BP_Flashlight_2023_11_30.uasset  (usar versión, no fecha)
❌ BP_FlashlightMejorado.uasset     (no español)
❌ WBP_HUDisplay.uasset             (HUD, no HUDisplay)
❌ tree.fbx                          (mayúscula inicial, camelCase)
❌ wind-loop-soft.wav               (snake_case con guión)
❌ IMPLEMENTATION_LOG.txt            (.md, no .txt)

✅ Correcto:
✅ BP_Flashlight_v01.uasset
✅ BP_Flashlight_v02.uasset
✅ WBP_HUD_v01.uasset
✅ Tree_Oak_v01.fbx
✅ Loop_Wind_Soft_v01.wav
✅ IMPLEMENTATION_LOG.md
```

---

## 📋 Checklist de Nombres

Antes de guardar/subir un archivo, verifica:

- [ ] ¿Tiene prefijo apropiado? (BP_, WBP_, SM_, etc.)
- [ ] ¿Es descriptivo el nombre?
- [ ] ¿Tiene versión? (v01, v02, etc.)
- [ ] ¿Usa mayúsculas correctamente? (camelCase o SCREAMING_SNAKE_CASE)
- [ ] ¿Está en la carpeta correcta?
- [ ] ¿Es consistente con otros archivos similares?
- [ ] ¿No tiene caracteres especiales?
- [ ] ¿No tiene espacios?

---

## 🔄 Changelog de Versión

Cuando incrementas versión, documenta:

```
BP_Flashlight_v01.uasset:
  - Funcionalidad base de linterna
  - Encender/apagar con entrada
  - Luz dinámica

BP_Flashlight_v02.uasset:
  - Agregado sistema de batería
  - Parpadeo cuando batería baja
  - Sonido de encendido/apagado

BP_Flashlight_v03.uasset:
  - Arreglado bug: luz desaparecía al correr
  - Optimización de performance
```

Documenta esto en tu `IMPLEMENTATION_LOG.md`:

```markdown
## Flashlight System

### v01 - Base Implementation
- [x] Blueprint structure
- [x] On/Off toggle
- [x] Light component

### v02 - Battery System
- [x] Battery UI element
- [x] Drain over time
- [x] Flicker when low
- [x] Sound effects

### v03 - Optimizations
- [x] Fix light disappear bug
- [x] Performance improvements
```

---

## 📞 Resumen Rápido

| Tipo | Prefijo | Ejemplo |
|------|---------|---------|
| Blueprint | `BP_` | `BP_Player_v01.uasset` |
| Widget | `WBP_` | `WBP_HUD_v01.uasset` |
| Static Mesh | `SM_` | `SM_Tree_Oak_v01.uasset` |
| Skeletal Mesh | `SK_` | `SK_Player_v01.uasset` |
| Material | `M_` | `M_Wood_Oak_v01.uasset` |
| Texture Color | `_D` | `Wood_Oak_D.tga` |
| Texture Normal | `_N` | `Wood_Oak_N.tga` |
| Audio Loop | `Loop_` | `Loop_Wind_Soft_v01.wav` |
| Audio SFX | `SFX_` | `SFX_DoorOpen_v01.wav` |
| Documento Guía | `SCREAMING_SNAKE_CASE` | `BLUEPRINT_STANDARDS.md` |

---

**Última actualización:** 31 de Julio, 2026  
**Contacto:** grupitopro026@gmail.com
