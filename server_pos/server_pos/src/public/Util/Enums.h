#pragma once

enum ServertStatus {
    OK,
    UNKNOWN,
    ID_EXISTS,
    PLAYER_ID_DOESNT_EXISTS,
};

enum ServertInput {
    MOVE_RIGHT,
    MOVE_LEFT,
    MOVE_UP,
    MOVE_DOWN,
};

enum EntityType {
    Player,
    Enemy
};