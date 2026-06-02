# Balatro Blind Progression & Skip Reward System
Course: Design Pattern untuk Game

## Architectural Implementations

### 1. State Pattern (Blind System)
We decoupled blind progression from conditional branch structures by implementing abstract states via `BlindState`. The gameplay loop safely routes requirements, rewards, and state steps across concrete state files:
* `SmallBlindState` -> Progresses directly to Big Blind
* `BigBlindState` -> Progresses directly to Boss Blind
* `BossBlindState` -> Increments Ante tracker and loops back to a fresh sequence cycle

### 2. Command Pattern (Skip Reward Infrastructure)
When skipping a blind, concrete `RewardCommand` instances are deferred, populated dynamically via state factory overrides, and stored inside a pending storage collection within the runtime manager. These commands are executed safely via discrete processing hooks (`Start`, `NextBlind`, `NextAnte`).

### 3. Chain of Responsibility Pattern (Scoring)
Our scoring framework relies on an interconnected series of evaluation nodes (`PokerHandChecker`), ensuring hand scoring metrics remain completely modular and decoupled from session progression mechanics.