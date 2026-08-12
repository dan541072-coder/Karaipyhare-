# Flujo Visual - Sistema de Puertas en Blueprints

## Estructura del Blueprint

```
BP_Door (Actor)
│
├─ Components
│  ├─ DoorMesh (Static Mesh Component)
│  └─ BoxCollision (Box Collision) [opcional]
│
├─ Variables
│  ├─ bIsOpen
│  ├─ bAutoClose
│  ├─ OpenDuration / CloseDuration
│  ├─ DoorRotation / DoorOffset
│  └─ DoorType ("Rotating" o "Sliding")
│
├─ Timeline
│  └─ DoorTimeline
│     ├─ Float Track: Interpolation (0 → 1)
│     └─ Duration: Variable según OpenDuration
│
└─ Functions
   ├─ OpenDoor()
   ├─ CloseDoor()
   └─ ToggleDoor()
```

---

## Event Graph Minimal

```
┌─────────────────────────────────────────┐
│           EVENT BEGIN PLAY              │
└────────────────┬────────────────────────┘
                 │
        ┌────────┴────────┐
        │                 │
    ┌───▼──┐          ┌───▼──┐
    │SET   │          │SET   │
    │Init  │          │Init  │
    │Rot   │          │Loc   │
    └───┬──┘          └───┬──┘
        └────────┬────────┘
                 │
            [Listo para abrir]
```

---

## Diagrama: OpenDoor()

```
┌──────────────┐
│  OpenDoor()  │
└──────┬───────┘
       │
       ├─→ Is Already Open? ──┐
       │         ↓             │
       │   YES ──┘─ RETURN     │
       │         NO            │
       │         ↓             │
       ├─→ Set bIsOpen = True  │
       │                       │
       ├─→ Play DoorTimeline   │
       │   (Duration = OpenDuration)
       │                       │
       └─→ If bAutoClose?      │
           ├─ YES              │
           │  └─ Delay & Close │
           │                   │
           └─ NO               │
              └─ (fin)         │
                                │
                          [Puerta abierta]
```

---

## Diagrama: Timeline Update

```
┌────────────────────────────────────┐
│     DoorTimeline Update            │
│     Alpha: 0 → 1 (según duration)  │
└────────────┬───────────────────────┘
             │
        ┌────┴─────┐
        │           │
    [Get Value]     │
        │           │
    ┌───▼─────────┐ │
    │ If Rotating │ │
    └───┬─────────┘ │
        │           │
    ┌───▼─────────────────┐
    │ Lerp Rotator        │
    │ From: InitialRot    │
    │ To: InitialRot +    │
    │     DoorRotation    │
    │ Alpha: Timeline Val │
    └───┬─────────────────┘
        │
    ┌───▼──────────────────┐
    │ Set Relative Rot     │
    │ (en DoorMesh)        │
    └──────────────────────┘
        │
    [Puerta rota suavemente]
```

---

## Caso de Uso: Puerta con Interacción Manual

```
Character Blueprint
│
├─ Input "E" (Interact)
│  │
│  └─ Line Trace Forward (1000 units)
│     │
│     └─ Get Hit Actor
│        │
│        └─ Cast to BP_Door?
│           ├─ YES:
│           │  └─ Toggle Door ◄── Llama función
│           │
│           └─ NO: Hacer otra cosa
```

---

## Caso de Uso: Puerta Automática

```
Level
│
├─ BP_Door
│  └─ BoxCollision (On Overlap Events)
│
└─ Player/Enemy Pawn
   │
   └─ Enter Trigger Volume
      │
      └─ On Actor Begin Overlap
         │
         └─ Cast to Pawn?
            ├─ YES: Open Door ◄── Puerta se abre
            │
            └─ On Actor End Overlap
               │
               └─ Delay 3s → Close Door ◄── Puerta se cierra
```

---

## Conexiones en Timeline Update

```
Timeline → Get Float Value → Branch on DoorType
                                    │
                ┌───────────────────┼───────────────────┐
                │                   │                   │
          [Rotating]          [Sliding]          [Otra]
                │                   │
            Lerp Rotator        Lerp Vector
            (Init + Delta)      (Init + Offset)
                │                   │
                └───────────────────┘
                          │
                    Set Component
                  (Rotation o Location)
```

---

## Variables Clave

| Variable | Tipo | Uso |
|----------|------|-----|
| `bIsOpen` | Bool | Rastrear estado actual |
| `OpenDuration` | Float | Velocidad de apertura (segundos) |
| `CloseDuration` | Float | Velocidad de cierre |
| `AutoCloseDelay` | Float | Segundos antes de cerrar automático |
| `DoorRotation` | Rotator | Ángulo final (ej: 0,90,0) |
| `DoorOffset` | Vector | Distancia de traslación (Sliding) |
| `InitialRotation` | Rotator | Posición inicial (guardada en BeginPlay) |
| `InitialLocation` | Vector | Ubicación inicial (guardada en BeginPlay) |

---

## Performance

- Timeline usa native code (muy eficiente)
- No hace Tick (solo actualiza durante timeline)
- Soporta múltiples puertas sin problema
- Light footprint en memoria

---

## Tips

✓ Usa DoorType como string o enum para escalabilidad  
✓ Timeline se puede pausar/reanudar si lo necesitas  
✓ Puedes agregar sonidos en Timeline Updated  
✓ Los delays pueden ser loops (temporizador de cierre)
