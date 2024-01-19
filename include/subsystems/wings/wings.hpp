#ifndef __WINGS
#define __WINGS

namespace thunderbird {
    class Wings {

        bool leftWingIsOpen = false;
        bool rightWingIsOpen = false;
        
        public:
        void runWings();

        void openFrontWings();
        void closeFrontWings();

        void openFrontLeft();
        void openFrontRight();
        void closeFrontLeft();
        void closeFrontRight();

        void openBackWings();
        void closeBackWings();

        void openBackLeft();
        void openBackRight();
        void closeBackLeft();
        void closeBackRight();

    };
}

#endif