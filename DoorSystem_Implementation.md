# Guía de Implementación - Sistema de Puertas

## Paso 1: Integración en C++

1. Copia `Door.h` y `Door.cpp` a tu carpeta `Source/YourProject/`
2. Abre tu archivo `.Build.cs` y asegúrate de que incluya los módulos necesarios
3. Compila el proyecto: `Ctrl + Shift + B`

## Paso 2: Crear Blueprint Base

1. En el Content Browser, crea nueva carpeta: `Blueprints/Doors/`
2. Click derecho → Blueprint Class → Selecciona `ADoor` como padre
3. Nombra: `BP_Door_Base`

### Configuración Inicial

En la ventana de Details:

```
Door | Mesh:
  - Static Mesh: Selecciona tu malla de puerta (ej: SM_Door)
  - Material: Aplica material deseado

Door | Config:
  - Door Type: Rotating (o Sliding)
  - Door Rotation: 0, 90, 0 (rotación 90° en eje Z)
  - Open Duration: 0.5
  - Close Duration: 0.5
  - Auto Close: True
  - Auto Close Delay: 3.0
  - Easing Curve: Linear (o crear curva personalizada)
```

## Paso 3: Crear Variantes de Puertas

### Puerta Estándar Rotativa
```
BP_StandardDoor (Hereda de BP_Door_Base)
  - Door Type: Rotating
  - Door Rotation: 0, 90, 0
```

### Puerta Corrediza
```
BP_SlidingDoor (Hereda de BP_Door_Base)
  - Door Type: Sliding
  - Door Offset: 200, 0, 0  (traslación en X)
```

### Puerta Automática
```
BP_AutomaticDoor (Hereda de BP_Door_Base)
  - Auto Close: True
  - Auto Close Delay: 2.0
  - Open Duration: 0.8
```

## Paso 4: Integración con Gameplay

### En Blueprint (Event Graph)

#### Abrir por Overlap
```
Event Actor Begin Overlap
  → Cast to Pawn
  → If Valid
    → Call "Open Door"
```

#### Interactividad Manual
```
Input Action "Interact"
  → Line Trace (desde cámara, 1000 unidades)
  → If Hit Door Actor
    → Call "Toggle Door"
```

#### Con Eventos de Sonido
```
On Door Started Opening
  → Play Sound 2D (SFX_DoorOpen)

On Door Opened
  → Play Sound 2D (SFX_DoorOpened)
  → Spawn Emitter (opcional)
```

## Paso 5: Colocar en Nivel

1. Arrastra `BP_StandardDoor` al nivel
2. Posiciona en frame de puerta
3. Ajusta transformación inicial
4. Prueba con `OpenDoor()` / `CloseDoor()`

## Testing

### En PIE (Play in Editor)

- **Apertura manual**: `GetOwningPlayerController()` → `Cast to ADoor` → `OpenDoor()`
- **Cierre automático**: Espera 3 segundos después de abrir
- **Toggle**: Llamar varias veces rápido (no debe glitchear)

### Debugging

```blueprint
Print String: "Door State: " + CurrentState
Print String: "Is Open: " + bIsOpen
```

## Casos Avanzados

### Puerta con Cerradura (extensión)
En Blueprint, agregar:
- Boolean `bIsLocked`
- Check en `OpenDoor()`: Si bIsLocked, no abrir

### Puerta Temporizada
- `Auto Close: True`
- `Auto Close Delay: 10.0` (10 segundos)

### Puerta Multi-Estado
- Crear enum: Closed, PartiallyOpen, FullyOpen
- Extender lógica de Timeline

## Notas Técnicas

- El Timeline maneja toda la interpolación
- Los eventos se casan automáticamente (Opened, Closed)
- No hay restricción de velocidad (ajustable con OpenDuration/CloseDuration)
- Compatible con Level Streaming (se destruye con el nivel)
