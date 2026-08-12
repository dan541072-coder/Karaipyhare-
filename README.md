# 🎮 KARAIPYHARE - Proyecto de Juego de Terror

**Unreal Engine 5.1.1** | **Equipo:** 3 Personas | **Estado:** En Desarrollo 🚀

![Horror Game](https://img.shields.io/badge/Genre-Horror-red) ![Unreal Engine](https://img.shields.io/badge/Engine-UE5.1.1-blue) ![Status](https://img.shields.io/badge/Status-Active-green)

---

## 📌 Descripción Rápida

Karaipyhare es un juego de terror en primera persona desarrollado en Unreal Engine 5.1.1 con un equipo de 3 desarrolladores especializados en programación, diseño de niveles y arte 3D/sonido.

El proyecto utiliza una estructura de carpetas profesional para evitar conflictos de versión y garantizar colaboración fluida.

---

## 👥 Equipo

| Rol | Responsabilidades | Carpeta Principal |
|-----|------|---------|
| **👨‍💻 Programador (Blueprints)** | Lógica de juego, sistemas, UI | `/Content/Programming/` |
| **🗺️ Diseñador de Niveles** | Mapas, iluminación, atmósfera | `/Content/LevelDesign/` |
| **🎨 Artista 3D / Sonido** | Modelos, texturas, audio | `/Content/Assets/` |

---

## 🗂️ Estructura de Carpetas

```
Content/
├── Programming/       # Blueprints, C++, Widgets
├── LevelDesign/       # Mapas, iluminación, prototipos
├── Assets/            # Modelos 3D, texturas, audio
├── Shared/            # Documentación, backups, testing
└── StarterContent/    # Referencia (NO modificar)
```

**📖 Documentación completa:** Ver `ESTRUCTURA_PROYECTO_KARAIPYHARE.md`

---

## 🚀 Guía Rápida de Inicio

### 1️⃣ **Para el Programador (Blueprints)**
```
Ubicación: Content/Programming/

Crear Blueprints en:
├── Blueprints/Character/        → Personaje, movimiento
├── Blueprints/Interactions/      → Puertas, objetos, interacciones
├── Blueprints/Enemies/           → Enemigos, IA
├── Blueprints/Systems/           → GameMode, GameState
└── Blueprints/UI/                → HUD, indicadores

Convención: BP_{Tipo}_{Nombre}_v01
Ejemplo: BP_Door_Wooden_v01
```

### 2️⃣ **Para el Diseñador de Niveles**
```
Ubicación: Content/LevelDesign/

Crear mapas en:
├── Maps/MainMap/                 → Mapa principal del juego
├── Maps/TestMaps/                → Pruebas rápidas
└── Maps/Prototypes/              → Prototipos nuevos

Luego configurar:
├── Lighting/                      → Iluminación temática
└── Fog_and_Atmosphere/            → Niebla y efectos

Convención: MAP_{Nombre}_v01
Ejemplo: MAP_MainLevel_v01
```

### 3️⃣ **Para el Artista 3D / Sonido**
```
Ubicación: Content/Assets/

Crear:
├── 3D_Models/                    → Objetos, edificios, props
├── Materials/                    → Materiales Unreal
├── Textures/                     → Texturas PBR (Diffuse, Normal, Roughness)
└── Audio/                        → Sonidos ambientales, SFX, voz

Convenciones:
- Blueprints: BP_..._v01
- Materiales: M_{Nombre}_{Tipo}
- Texturas: T_{Nombre}_{MapType}
- Sonidos: S_{Tipo}_{Nombre}
```

---

## 🏷️ Convenciones de Nombres

### **Regla General**
```
{Prefijo}_{Descripción}_{Variante}_v{Número}

Ejemplos:
✅ BP_Character_Player_v01
✅ M_Wood_Rough
✅ T_Stone_N
✅ S_Ambient_Wind_Loop
✅ MAP_MainLevel_v01
```

### **Prefijos Estándar**

| Tipo | Prefijo | Ejemplo |
|------|---------|---------|
| Blueprint | `BP_` | `BP_Door_Wooden_v01` |
| Material | `M_` | `M_Stone_Wet` |
| Textura | `T_` | `T_Wood_N` |
| Skeletal Mesh | `SK_` | `SK_Character_Zombie` |
| Animación | `A_` | `A_Character_Walk` |
| Sonido | `S_` | `S_Ambient_Wind` |
| Mapa | `MAP_` | `MAP_MainLevel_v01` |

---

## ⚠️ Reglas de Colaboración

### ✅ **HAZLO**
- ✅ Usar nombres descriptivos en INGLÉS
- ✅ Versionear archivos críticos (v01, v02, v03)
- ✅ Agrupar por categoría dentro de carpetas
- ✅ Comunicar cambios grandes al equipo
- ✅ Hacer backup de versiones estables

### ❌ **NO HAGAS**
- ❌ Crear carpetas desorganizadas ("MisArchivos", "Misc")
- ❌ Compartir mapas sin versión en nombre
- ❌ Modificar assets ajenos sin permiso
- ❌ Tocar StarterContent
- ❌ Mezclar roles (programador creando modelos)

---

## 🔄 Flujo de Trabajo Típico

```
1. PLANIFICACIÓN (Notion)
   ↓
2. DESARROLLO en carpeta de rol
   ├─ Programador: /Programming/Blueprints/
   ├─ Diseñador: /LevelDesign/Maps/TestMaps/
   └─ Artista: /Assets/
   ↓
3. NOMBRAR CON VERSIÓN (_v01)
   ↓
4. INTEGRACIÓN en carpeta final
   ↓
5. BACKUP en /Shared/VCS/Versions/
   ↓
6. ✅ LISTO PARA EQUIPO
```

---

## 📞 Contacto y Recursos

| Recurso | Link/Info |
|---------|-----------|
| **Gestor Proyecto** | Los pros (grupitopro026@gmail.com) |
| **Herramientas** | Notion, Unreal Engine 5.1.1, Blender |
| **Documentación** | `ESTRUCTURA_PROYECTO_KARAIPYHARE.md` |
| **Versionado** | `/Content/Shared/VCS/Versions/` |

---

**Última Actualización:** 31 Julio 2026  
**Responsable:** Los pros  
**Estado:** ✅ ACTIVO
