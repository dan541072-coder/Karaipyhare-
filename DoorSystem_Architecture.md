# Sistema de Mecánica de Puertas - Unreal Engine

## Descripción General
Sistema modular de puertas con animaciones suaves, interactividad y estados configurables.

## Estructura

### Clases Base

#### ADoor (C++)
- Clase padre para todas las puertas
- Gestiona estado (abierta/cerrada)
- Controla animaciones de rotación/traslación
- Timeline para transiciones suaves
- Eventos de apertura/cierre

#### Propiedades Configurables
```
- bIsOpen: Estado actual
- DoorRotation / DoorOffset: Rotación o traslación final
- OpenDuration: Tiempo de apertura (segundos)
- CloseDuration: Tiempo de cierre (segundos)
- bAutoClose: Cierre automático después de tiempo
- AutoCloseDelay: Retardo antes de cerrar (segundos)
- EasingFunction: Tipo de interpolación
```

### Blueprint Child Classes
Crear blueprints específicos para:
- **Standard Door**: Puerta simple que rota
- **Sliding Door**: Puerta corrediza
- **Garage Door**: Puerta de garaje
- **Secret Door**: Puerta oculta

## Workflow

1. **Crear Blueprint** basado en `ADoor`
2. **Configurar parámetros** (rotación, velocidad, delay)
3. **Asignar animación** en el Timeline
4. **Colocar en nivel** y ajustar

## Eventos Disponibles

```
- OnDoorOpened()
- OnDoorClosed()
- OnDoorStartOpening()
- OnDoorStartClosing()
```

Usar para:
- Sonidos
- Efectos visuales
- Triggear cinemáticas
- Cambiar luces

## Ejemplos de Uso

### Puerta Simple
1. Rotación 90° en eje Z
2. OpenDuration: 0.5s
3. AutoClose: True, Delay: 3s

### Puerta Corrediza
1. Offset 200cm en eje X
2. OpenDuration: 0.8s
3. Easing: EaseInOut

## Notas
- Los Timelines manejan interpolación suave
- Usar `SetDoorState()` para cambios programáticos
- Los eventos permiten composición (sonidos, VFX, etc.)
