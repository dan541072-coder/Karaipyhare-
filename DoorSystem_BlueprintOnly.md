# Sistema de Puertas - Blueprint Only

## Crear Blueprint Base (Sin C++)

### Paso 1: Crear el Blueprint

1. Content Browser → Click derecho → Blueprint Class
2. Selecciona **Actor** como clase padre
3. Nombra: `BP_Door`

### Paso 2: Agregar Componentes

En el panel Components:

```
Root (Scene Component)
├─ DoorMesh (Static Mesh Component)
└─ BoxCollision (Box Collision Component) [opcional, para interacción]
```

**Configurar DoorMesh:**
- Static Mesh: Asigna tu malla de puerta
- Generate Overlap Events: True (si usas overlap)

### Paso 3: Agregar Variables

En el panel Variables (Details):

```
Variables
├─ bIsOpen (Boolean) - Default: False
├─ bAutoClose (Boolean) - Default: True
├─ AutoCloseDelay (Float) - Default: 3.0
├─ OpenDuration (Float) - Default: 0.5
├─ CloseDuration (Float) - Default: 0.5
├─ DoorRotation (Rotator) - Default: (0, 90, 0)
├─ DoorOffset (Vector) - Default: (0, 0, 0)
├─ InitialRotation (Rotator) - Private
├─ InitialLocation (Vector) - Private
└─ DoorType (String) - Default: "Rotating"
```

### Paso 4: Event Graph

#### Event BeginPlay

```
Event BeginPlay
├─ Set InitialRotation = DoorMesh Get Relative Rotation
├─ Set InitialLocation = DoorMesh Get Relative Location
└─ (fin)
```

#### Función: Open Door

Crea función **OpenDoor** (Callable):

```
OpenDoor
├─ Is Open? → Branch
│  ├─ True: Return
│  └─ False:
│     ├─ Set bIsOpen = True
│     ├─ Play Timeline "DoorTimeline"
│     └─ (si bAutoClose)
│        └─ Delay AutoCloseDelay → Call CloseDoor
```

#### Función: Close Door

Crea función **CloseDoor** (Callable):

```
CloseDoor
├─ Is Open? → Branch
│  ├─ True:
│  │  ├─ Set bIsOpen = False
│  │  └─ Reverse Timeline "DoorTimeline"
│  └─ False: Return
```

#### Función: Toggle Door

```
ToggleDoor
├─ Is Open? → Branch
│  ├─ True: Call CloseDoor
│  └─ False: Call OpenDoor
```

### Paso 5: Crear Timeline

1. En el Event Graph, arrastra desde variable → Crea nuevo Timeline
2. Nombra: **DoorTimeline**
3. En el Timeline Editor:

```
Agregar Float Track
├─ Nombra: "Interpolation"
├─ Click derecho → Add Key (0, 0)
└─ Click derecho → Add Key (OpenDuration, 1.0)
└─ Ajusta curva (suave)
```

### Paso 6: Conectar Timeline a Movimiento

En el Event Graph, conecta:

```
DoorTimeline Update
├─ Get Timeline Value "Interpolation"
├─ Branch (DoorType == "Rotating")
│  ├─ True:
│  │  ├─ Lerp Rotator
│  │  │  ├─ A: InitialRotation
│  │  │  ├─ B: InitialRotation + DoorRotation
│  │  │  └─ Alpha: Timeline Value
│  │  └─ DoorMesh Set Relative Rotation
│  └─ False:
│     ├─ Lerp Vector
│     │  ├─ A: InitialLocation
│     │  ├─ B: InitialLocation + DoorOffset
│     │  └─ Alpha: Timeline Value
│     └─ DoorMesh Set Relative Location
```

---

## Usar en Nivel

### Opción 1: Puerta Manual (Toggle)

Agregar esto al Character Blueprint:

```blueprint
Input Interact (E)
├─ Line Trace by Channel (1000 units adelante)
├─ Get Hit Actor
├─ Cast to BP_Door
├─ If Valid:
│  └─ Call Toggle Door
```

### Opción 2: Puerta Automática (Overlap)

En BP_Door, agregar:

```blueprint
Event Actor Begin Overlap (BoxCollision)
├─ Cast to Pawn
├─ If Valid:
│  └─ Call Open Door

Event Actor End Overlap
├─ Call Close Door (delay 3 segundos)
```

### Opción 3: Puerta con Sonido

En OpenDoor:

```
OpenDoor
├─ Play Sound 2D (SFX_DoorOpen)
├─ Play Timeline
└─ Delay 0.5 → Play Sound 2D (SFX_DoorLatch)
```

---

## Variantes Rápidas

### Puerta Corrediza
```
DoorType: "Sliding"
DoorRotation: (0, 0, 0)
DoorOffset: (200, 0, 0)
```

### Puerta Doble
```
Crear 2 mallas: DoorLeft, DoorRight
Puerta izq: DoorRotation (0, -45, 0)
Puerta der: DoorRotation (0, 45, 0)
```

### Puerta Rápida
```
OpenDuration: 0.2
CloseDuration: 0.2
AutoCloseDelay: 1.0
```

---

## Troubleshooting

**Puerta no se mueve:** ¿Conectaste el Timeline Update al Set Relative Rotation/Location?

**Movimiento jerky:** Baja OpenDuration (ej: 0.3)

**No cierra automático:** Verifica bAutoClose = True

**Colisiones raras:** Desactiva Collision en DoorMesh, usa Collision box separada
