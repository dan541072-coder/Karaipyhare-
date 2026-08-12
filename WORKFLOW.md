# 🔄 Workflow de Colaboración - KaraipyHare Project

**Sistema:** Git + Notion + Unreal Engine 5.1.1  
**Objetivo:** Trabajo sincronizado sin conflictos

---

## 📋 Flujo Completo de Trabajo

```
┌─────────────────────────────────────────────────────┐
│          1️⃣ PLANIFICACIÓN (Notion)                 │
│  • Crear task en Notion                            │
│  • Describir qué se va a hacer                      │
│  • Asignar a responsable                            │
│  • Cambiar estado a "In Progress"                   │
└────────────────────┬────────────────────────────────┘
                     │
┌────────────────────▼────────────────────────────────┐
│          2️⃣ PREPARACIÓN (Git)                       │
│  • git pull (sincronizar con main)                  │
│  • git checkout -b feature/descripcion              │
│  • Nueva rama para la tarea                         │
└────────────────────┬────────────────────────────────┘
                     │
┌────────────────────▼────────────────────────────────┐
│          3️⃣ DESARROLLO (Unreal + Git)               │
│  • Trabajar en carpeta Work_In_Progress             │
│  • Commits frecuentes con versión: v01 → v02       │
│  • Probar cambios localmente                        │
│  • Documentar en IMPLEMENTATION_LOG.md              │
└────────────────────┬────────────────────────────────┘
                     │
┌────────────────────▼────────────────────────────────┐
│          4️⃣ FINALIZACIÓN (Git)                      │
│  • Versión final: v99 (opcional)                    │
│  • Mover a carpeta principal (no WIP)               │
│  • Último commit con mensaje descriptivo            │
│  • git push origin feature/descripcion              │
└────────────────────┬────────────────────────────────┘
                     │
┌────────────────────▼────────────────────────────────┐
│          5️⃣ REVISIÓN (Pull Request)                 │
│  • Crear PR en GitHub                              │
│  • Pedir revisión a compañero                       │
│  • Atender comentarios y feedback                   │
│  • Hacer cambios si es necesario                    │
└────────────────────┬────────────────────────────────┘
                     │
┌────────────────────▼────────────────────────────────┐
│          6️⃣ MERGE (Git)                             │
│  • Merge a rama main                                │
│  • Eliminar rama feature                            │
│  • Actualizar rama local: git pull                  │
└────────────────────┬────────────────────────────────┘
                     │
┌────────────────────▼────────────────────────────────┐
│          7️⃣ CIERRE (Notion)                         │
│  • Cambiar estado de task a "Done"                  │
│  • Agregar link a PR / commit                       │
│  • Notas finales si aplica                          │
└─────────────────────────────────────────────────────┘
```

---

## 💻 Comandos Git Esenciales

### Inicio de sesión / Setup

```bash
# Configurar Git la primera vez
git config --global user.name "Tu Nombre"
git config --global user.email "tu@email.com"

# Clonar el repositorio
git clone <url-del-repositorio>
cd KaraipyHare_Project
```

### Antes de empezar a trabajar

```bash
# Actualizar main desde repositorio remoto
git pull origin main

# Ver en qué rama estoy
git branch

# Ver todas las ramas
git branch -a
```

### Crear una nueva rama para tu tarea

```bash
# Rama para nueva feature
git checkout -b feature/player-movement

# Rama para bugfix
git checkout -b bugfix/flashlight-disappear

# Rama para refactoring
git checkout -b refactor/interaction-system

# Rama para documentación
git checkout -b docs/blueprint-standards
```

### Guardar cambios frecuentes

```bash
# Ver archivos modificados
git status

# Agregar archivos específicos
git add 1_Programming/Blueprints/Characters/BP_Player_v02.uasset
git add 1_Programming/Documentation/IMPLEMENTATION_LOG.md

# Agregar todos los cambios (¡cuidado!)
git add .

# Hacer commit con versión clara
git commit -m "feat: Add player stamina system (v01 → v02)"
git commit -m "fix: Flashlight bug when running (v01 → v02)"
git commit -m "docs: Update implementation log"

# Ver historial de commits
git log --oneline
```

### Subir cambios al repositorio

```bash
# Subir tu rama
git push origin feature/player-movement

# La primera vez te pedirá que crees la rama remota:
# git push --set-upstream origin feature/player-movement
```

### Sincronizar si main cambió

```bash
# Mientras trabajas en tu rama, si main se actualiza:
git fetch origin

# Traer cambios de main a tu rama
git rebase origin/main

# O merge si prefieres (genera commit extra)
git merge origin/main
```

### Ver diferencias antes de commit

```bash
# Ver qué cambiaste
git diff

# Ver cambios de un archivo específico
git diff 1_Programming/Blueprints/Characters/BP_Player_v02.uasset

# Ver cambios que ya staged (git add)
git diff --staged
```

---

## 📱 Estructura de Commits

### Formato recomendado:

```
<tipo>: <descripción> (v<versión_anterior> → v<versión_nueva>)

Ejemplo:
feat: Add player stamina system (v01 → v02)
fix: Flashlight disappears when running (v01 → v02)
refactor: Optimize interaction blueprint (v02 → v03)
docs: Update implementation log
chore: Merge conflict resolved in BP_Player
```

### Tipos de commits:

| Tipo | Uso | Ejemplo |
|------|-----|---------|
| `feat` | Nueva característica | `feat: Add enemy AI system` |
| `fix` | Arreglar bug | `fix: Door not opening correctly` |
| `refactor` | Mejora de código | `refactor: Simplify lighting system` |
| `docs` | Documentación | `docs: Update README` |
| `style` | Formato (no afecta funcionalidad) | `style: Organize folder structure` |
| `chore` | Mantenimiento | `chore: Merge conflict resolved` |
| `test` | Tests | `test: Add unit tests for inventory` |
| `perf` | Optimización | `perf: Reduce draw calls by 20%` |

### Ejemplos de commits bien hechos:

```bash
git commit -m "feat: Implement flashlight blueprint with battery system (v01 → v02)"
git commit -m "fix: Player collision not working on slopes (v02 → v03)"
git commit -m "refactor: Extract door logic to separate blueprint (v01 → v02)"
git commit -m "docs: Add lighting guide and presets documentation"
git commit -m "feat: Add forest ambience with wind loops (v01 → v01)"
```

### Ejemplos de commits MAL hechos:

```bash
❌ git commit -m "cambios"
❌ git commit -m "arreglado"
❌ git commit -m "v01"
❌ git commit -m "updated files"
❌ git commit -m "trabajo del día"
```

---

## 🔄 Pull Request (PR) - Revisión de Código

### Crear una PR en GitHub:

1. **Ve a GitHub** → Tu fork/rama
2. **Click en "Compare & pull request"**
3. **Titulo:** Mismo que tu rama
   ```
   [FEATURE] Player Movement System
   [BUGFIX] Flashlight Disappear Bug
   [REFACTOR] Interaction System
   ```
4. **Descripción de la PR:**
   ```markdown
   ## Descripción
   Implementé el sistema de movimiento del jugador.

   ## ¿Qué cambió?
   - Agregado blueprint BP_Player_v02
   - Sistema de stamina
   - Animaciones de correr

   ## ¿Cómo probarlo?
   1. Juega el nivel TestLevel
   2. Presiona W para caminar
   3. Presiona Shift para correr
   4. Verifica que la stamina baja

   ## Screenshots / Videos
   [adjunta si es posible]

   ## Tareas relacionadas
   Closes #123 (si hay issue en GitHub)
   Relacionado a task en Notion: [link]

   ## Cambios de archivos
   - 1_Programming/Blueprints/Characters/BP_Player_v02.uasset
   - 1_Programming/Blueprints/Systems/BP_Stamina_v01.uasset
   - 1_Programming/Documentation/IMPLEMENTATION_LOG.md
   ```

5. **Asigna revisor:** Otro integrante del equipo
6. **Presiona "Create Pull Request"**

### Revisor: Cómo revisar una PR

```
1. Lee la descripción
2. Ve los cambios (tab "Files changed")
3. Abre Unreal Engine y sincroniza la rama
4. Prueba los cambios localmente
5. Comenta problemas línea por línea si hay
6. Aprueba con "Approve" o pide cambios con "Request changes"
```

### Atender feedback:

```bash
# Si el revisor pidió cambios:
# 1. Haz los cambios en Unreal
# 2. Incrementa versión: v01 → v02
# 3. Commit nuevamente
git add .
git commit -m "refactor: Address PR feedback (v02 → v03)"
git push origin feature/player-movement

# La PR se actualiza automáticamente
# El revisor verá los nuevos commits
```

### Hacer merge:

```bash
# Una vez aprobada, un admin hace merge
# O tú si tienes permisos:
# En GitHub: Presiona "Merge pull request"
# Elige "Squash and merge" o "Create a merge commit"
```

---

## 🗂️ Gestión de Ramas

### Ramas normales:

```
main (rama principal, siempre estable)
  ├─ develop (rama de desarrollo)
  │   └─ feature/player-movement (tu rama)
  │   └─ feature/enemy-ai
  │   └─ feature/lighting-system
  │   └─ bugfix/door-bug
  │   └─ refactor/optimization
```

### Nombres de ramas correctos:

```
✅ feature/player-movement
✅ feature/enemy-ai
✅ feature/inventory-system
✅ bugfix/flashlight-bug
✅ bugfix/door-locked-issue
✅ refactor/interaction-system
✅ docs/api-documentation
✅ perf/reduce-draw-calls

❌ feature/nueva_caracteristica (español)
❌ feature/PlayerMovement (mayúscula)
❌ feature/player_movement (snake_case, usar kebab-case)
❌ feat/player-movement (usar "feature", no "feat")
❌ wip/something (no uses "wip" en rama, usa Work_In_Progress en archivos)
```

### Eliminar ramas locales viejas:

```bash
# Ver ramas locales
git branch -v

# Eliminar rama local
git branch -d feature/player-movement

# Forzar eliminación (cuidado)
git branch -D feature/player-movement

# Eliminar rama remota (en GitHub)
git push origin --delete feature/player-movement
```

---

## 📌 Notion: Integración con Tareas

### Crear una task en Notion:

```
Título: Player Movement System Implementation
Asignar a: [Programador]
Descripción:
  Implementar el sistema base de movimiento del jugador.
  
  Requerimientos:
  - [ ] Caminar con WASD
  - [ ] Correr con Shift (consume stamina)
  - [ ] Animaciones de movimiento
  - [ ] Documentación de blueprint
  
Etiquetas: #Programming #Blueprint #Feature
Fecha limite: [fecha]
Estado: To Do
```

### Estados de task en Notion:

| Estado | Significado |
|--------|-------------|
| `To Do` | No empezada |
| `In Progress` | Trabajando en ella |
| `In Review` | PR creado, esperando aprobación |
| `Done` | Completada y mergeada a main |

### Flujo de estado:

```
To Do → In Progress
       ↓
    (trabajas y haces commits)
       ↓
In Progress → In Review
       ↓
    (revisor verifica)
       ↓
In Review → Done
       ↓
    (task completada)
```

### Agregar link de PR a Notion:

```
En la task, agrega un campo con el link de tu PR:
PR: https://github.com/tuusuario/KaraipyHare/pull/42

Así otros ven dónde está el progreso.
```

---

## ⚠️ Resolución de Conflictos

### Caso: Dos personas modifican el mismo archivo

```
El programador modifica BP_Door_v01.uasset
El diseñador también modifica BP_Door_v01.uasset

Cuando intentan hacer merge → CONFLICTO
```

### Solución paso a paso:

#### 1. Identifica el conflicto:
```bash
git status
# Ves: "both modified: BP_Door_v01.uasset"
```

#### 2. Comunica con el compañero:
- Abre issue en GitHub o mensaje en Notion
- "Conflicto en BP_Door_v01, ¿qué cambios hiciste?"

#### 3. Resuelve manualmente:

**Opción A: Desde Unreal Engine**
```
1. Abre Unreal Engine
2. Navega a: 1_Programming/Blueprints/Systems/Interaction/
3. Abre BP_Door_v01
4. Verás los cambios conflictivos
5. Elige qué cambios mantener
6. Guarda como BP_Door_v02 (nueva versión)
```

**Opción B: Desde Git (para archivos de texto)**
```bash
# Abre el archivo en editor
vim 1_Programming/Documentation/IMPLEMENTATION_LOG.md

# Verás marcas de conflicto:
# <<<<<<< HEAD (tu cambio)
# tu código aquí
# =======
# código del otro
# >>>>>>> feature/enemy-ai

# Edita manualmente para combinar
# Guarda el archivo

# Marca como resuelto
git add 1_Programming/Documentation/IMPLEMENTATION_LOG.md
git commit -m "chore: Merge conflict resolved in IMPLEMENTATION_LOG"
git push origin feature/player-movement
```

#### 4. Crea nueva versión después de resolver:
```
BP_Door_v01.uasset  (conflictivo)
                 ↓
         (resuelto manualmente)
                 ↓
BP_Door_v02.uasset  (versión final)
```

#### 5. Notifica a tu compañero:
```
"Conflicto resuelto en BP_Door_v02. 
Combino tus cambios de interacción 
con mis cambios de animación."
```

---

## 🛡️ Evitar Conflictos

### Estrategias preventivas:

```
1. DIVIDE EL TRABAJO CLARAMENTE
   - Programador hace BP_Player.uasset
   - Diseñador NO toca BP_Player.uasset
   - Cada uno su archivo

2. BRANCHES SEPARADAS
   - Programador: feature/player-movement
   - Diseñador: feature/level-design
   - No trabajes en la misma rama

3. COMMITS FRECUENTES
   - Commit cada 30-60 min
   - git commit -m "..."
   - git push origin feature/...

4. PULL ANTES DE EMPEZAR
   - Cada mañana: git pull origin main
   - Asegúrate de tener cambios nuevos

5. COMUNICA EN NOTION
   - "Trabajo en BP_Door hoy"
   - "¿Necesitas cambiar BP_Player?"
   - Coordinación preventiva
```

---

## 📊 Checklist Diario

### ✅ Antes de empezar:
```
- [ ] Sincronicé cambios: git pull origin main
- [ ] Crié rama feature: git checkout -b feature/...
- [ ] Revisé tareas nuevas en Notion
- [ ] Actualicé task a "In Progress"
```

### ✅ Durante el trabajo:
```
- [ ] Incremento versión en archivos: v01 → v02
- [ ] Hago commit cada cambio importante
- [ ] Actualizo IMPLEMENTATION_LOG.md
- [ ] Pruebo cambios en Unreal
```

### ✅ Al final del día:
```
- [ ] Último commit con mensaje descriptivo
- [ ] git push origin feature/... (subir cambios)
- [ ] Si termina tarea, creo PR
- [ ] Actualizo Notion: estado y comentarios
```

### ✅ Al hacer PR:
```
- [ ] Descripción clara de cambios
- [ ] Versiones documentadas
- [ ] Screenshots si aplica
- [ ] Pedí revisión a compañero
- [ ] Actualicé Notion: "In Review"
```

### ✅ Al completar:
```
- [ ] PR aprobada y mergeada
- [ ] Rama eliminada localmente y remotamente
- [ ] Actualicé Notion: "Done"
- [ ] git pull origin main (sincronizar)
```

---

## 📞 Problemas Comunes

### Problema: "Git no encuentra mi rama"

```bash
# Solución:
git fetch origin          # Traer info de repositorio remoto
git branch -a            # Ver todas las ramas
git checkout feature/...  # Cambiar a tu rama
```

### Problema: "Hice cambios pero no hice commit"

```bash
# Solución:
git add .                                    # Agregar archivos
git commit -m "feat: Descripción de cambios" # Hacer commit
git push origin feature/...                  # Subir
```

### Problema: "Borré un archivo por error"

```bash
# Si NO hiciste commit:
git checkout -- archivo.uasset  # Restaurar

# Si ya hiciste commit:
git revert <commit-hash>        # Crear commit que revierte cambios
```

### Problema: "Tengo conflicto y no sé cómo resolverlo"

```bash
# 1. Comunica en Notion o Discord
# 2. Pide ayuda a otro integrante
# 3. Último recurso: abortar merge
git merge --abort
git rebase --abort

# Vuelve a intentar después con comunicación
```

### Problema: "Hice cambios en main en lugar de en rama"

```bash
# Solución:
git checkout -b feature/nombre-tarea  # Crear rama con cambios
git checkout main                     # Volver a main
git reset --hard origin/main          # Descartar cambios en main
```

---

## 🚀 Resumen de Workflow Rápido

```
CADA MAÑANA:
└─ git pull origin main                    (sincronizar)
└─ Revisar Notion para nuevas tasks        (planificación)

DURANTE EL DÍA:
└─ Trabajar en tu rama: feature/...        (desarrollo)
└─ Commits frecuentes: feat: ... (v01→v02) (guardar)
└─ Actualizar IMPLEMENTATION_LOG.md        (documentar)

CADA NOCHE:
└─ git push origin feature/...             (subir cambios)
└─ Actualizar Notion: estado de task       (comunicar)

AL TERMINAR TAREA:
└─ Crear Pull Request en GitHub            (revisión)
└─ Pedir revisión a compañero             (validación)
└─ Atender feedback                        (ajustes)
└─ Merge a main                            (integración)
└─ Marcar task como Done en Notion        (cierre)
```

---

**Última actualización:** 31 de Julio, 2026  
**Contacto:** grupitopro026@gmail.com
