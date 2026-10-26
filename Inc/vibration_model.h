
#ifndef VIBRATION_MODEL_H
#define VIBRATION_MODEL_H

typedef enum {
    NORMAL = 0,
    IMBALANCE_LIKE = 1,
    EXCESSIVE_VIBRATION = 2
} VibrationClass;

VibrationClass classify_vibration(float variance, float peak);

#endif
