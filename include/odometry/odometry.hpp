namespace odometry {
    class Odometry_System {


        // TODO: Figure out whether setting angle/positions to sensor values directly is more effective than keeping theoretical values
        float xPosition = 0, yPosition = 0, currentAngle = 0;

        public:

        // Utils
        float reduceTo360(float angle);
        float getAngleToPosition(float x1, float y1, float x2, float y2);

        // Getters
        float getXPosition();
        float getYPosition();
        float getAngle();

        // Convention: + is CLOCKWISE for angles, bottom left corner is (0, 0) top right is (144, 144)
        void moveToPositionAbsolute(float targetX, float targetY, float finalAngle);
        void moveToPositionRelative(float targetX, float targetY, float finalAngle);

        void turnToAngleAbsolute(float angle);
        void turnToAngleRelative(float angle);
    };
}