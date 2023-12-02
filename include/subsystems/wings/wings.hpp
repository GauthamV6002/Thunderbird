#ifndef __WINGS
#define __WINGS

namespace thunderbird {
    class Wings {

        bool leftWingIsOpen = false;
        bool rightWingIsOpen = false;

        bool autonRemoverIsExpanded = false;
        
        public:
        void openWings();
        void closeWings();
        void runWings();

        void openLeft();
        void openRight();

        void closeLeft();
        void closeRight();

        // Auton Remover
        void expandAutonRemover();
        void retractAutonRemover();
    };
}

#endif