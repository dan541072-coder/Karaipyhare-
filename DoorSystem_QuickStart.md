# Quick Start - Sistema de Puertas

## Setup en 5 minutos

### 1. Compilar
- Copia `Door.h` y `Door.cpp` a `Source/Project/`
- Compila (`Ctrl + Shift + B`)

### 2. Blueprint Base
- New Blueprint Class → ADoor → `BP_Door_Base`
- Asigna mesh de puerta en Details

### 3. Variante Standard
- New Blueprint → BP_Door_Base → `BP_StandardDoor`
- Door Type: **Rotating**
- Door Rotation: **(0, 90, 0)**

### 4. Colocar
- Arrastra `BP_StandardDoor` al nivel
- Click derecho → Edit Blueprint
- Event Graph → Agregar esto:

```blueprint
Event Begin Play
  ├─ Delay 2.0 segundos
  └─ Open Door

On Door Opened
  └─ Print String "¡Puerta abierta!"
```

### 5. Prueba
- Play (`F5`)
- Deberías ver la puerta abrirse a los 2 segundos

---

## Ejemplos Comunes

### Puerta con Botón

```blueprint
Construct (Event)
  └─ Create Widget (BP_DoorButton)
  └─ Add to Viewport

(En Widget)
Button Clicked
  └─ Get Owner
  └─ Cast to Character
  └─ Get Pawn Sensing Component
  └─ Line Trace (adelante 500 units)
  └─ If Hit Door:
      └─ Cast to ADoor
      └─ Call Toggle Door
```

### Puerta Automática (Sensor)

```blueprint
Trigger Volume

On Actor Begin Overlap
  └─ Cast to Character
  └─ If Pawn:
      └─ Open Door (del actor overlapped)

On Actor End Overlap
  └─ Close Door (después de 3 segundos)
```

### Puerta con Sonido y Efectos

```blueprint
On Door Started Opening
  ├─ Play Sound 2D (SFX_DoorOpen)
  └─ Spawn Emitter (Dust_Puff)

On Door Opened
  └─ Play Sound 2D (SFX_DoorLatch)
```

---

## Propiedades Clave

| Propiedad | Rango | Efecto |
|-----------|-------|--------|
| Open Duration | 0.1 - 5.0 | Velocidad de apertura (segundos) |
| Close Duration | 0.1 - 5.0 | Velocidad de cierre |
| Auto Close Delay | 0 - 30 | Segundos antes de cerrar automáticamente |
| Door Rotation | ±360 | Ángulos de rotación final |
| Door Offset | ±9999 | Distancia de traslación (Sliding) |

---

## Troubleshooting

**Puerta no se abre:**
- ✓ ¿Compilaste el código?
- ✓ ¿Blueprint hereda de ADoor?
- ✓ ¿Static Mesh está asignado?

**Animación choppy:**
- Baja Open/Close Duration (ej: 0.3)
- Usa Easing Curve en lugar de Linear

**Puerta se pega:**
- ✓ ¿Auto Close Delay es > 0?
- ✓ Aumenta Close Duration

---

## Siguiente Paso

Para interactividad:
1. Usa **Trigger Volumes** para puertas automáticas
2. Usa **Line Traces** para puertas manuales
3. Integra con **Dialogue System** para puertas bloqueadas
