#include "main.h"
#include "math.h"

#define FULL_CIRCLE 0x10000  // Value representing a full 360-degree rotation

// Precomputed target angles where tan(θ) = 1/2
#define TAN_THETA_1_2_1 0x12E4  // ~26.565°
#define TAN_THETA_1_2_2 0x52E4  // ~116.565°
#define TAN_THETA_1_2_3 0x92E9  // ~206.565°
#define TAN_THETA_1_2_4 0xD2FB  // ~296.435°

// Function to snap to the nearest angle where tan(θ) = 1/2
s32 snap_to_tan_theta_1_2(s32 current_rotation) {
    // Define the four target angles
    s32 target_angles[4] = {TAN_THETA_1_2_1, TAN_THETA_1_2_2, TAN_THETA_1_2_3, TAN_THETA_1_2_4};

    // Find the nearest target angle
    s32 min_diff = FULL_CIRCLE;
    s32 snapped_rotation = 0;

    for (s32 i = 0; i < 4; i++) {
        s32 diff = ABS(current_rotation - target_angles[i]);
        if (diff < min_diff) {
            min_diff = diff;
            snapped_rotation = target_angles[i];
        }
    }

    return snapped_rotation;
}

// Precomputed target angles where tan(θ) = 1/2, rotated by 90 degrees
#define TAN_THETA_1_2_ROT_1 0x2D2A  // ~63.435°
#define TAN_THETA_1_2_ROT_2 0x6D2F  // ~153.435° 
#define TAN_THETA_1_2_ROT_3 0xAD34  // ~243.435°
#define TAN_THETA_1_2_ROT_4 0xED26  // ~333.435º

// Function to snap to the nearest angle where tan(θ) = 1/2, rotated by 90 degrees
s32 snap_to_tan_theta_1_2_rotated_90(s32 current_rotation) {
    // Define the four target angles
    s32 target_angles[4] = {TAN_THETA_1_2_ROT_1, TAN_THETA_1_2_ROT_2, TAN_THETA_1_2_ROT_3, TAN_THETA_1_2_ROT_4};

    // Find the nearest target angle
    s32 min_diff = FULL_CIRCLE;
    s32 snapped_rotation = 0;

    for (s32 i = 0; i < 4; i++) {
        s32 diff = ABS(current_rotation - target_angles[i]);
        if (diff < min_diff) {
            min_diff = diff;
            snapped_rotation = target_angles[i];
        }
    }

    return snapped_rotation;
}