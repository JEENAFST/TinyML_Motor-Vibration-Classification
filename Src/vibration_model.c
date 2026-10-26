
/* Generated from the trained scikit-learn Decision Tree */

typedef enum {
    NORMAL = 0,
    IMBALANCE_LIKE = 1,
    EXCESSIVE_VIBRATION = 2
} VibrationClass;

VibrationClass classify_vibration(float variance, float peak)
{
    if (variance <= 0.12f) {
        return NORMAL;
    } else if (peak <= 1.02f) {
        return IMBALANCE_LIKE;
    } else {
        return EXCESSIVE_VIBRATION;
    }
}
