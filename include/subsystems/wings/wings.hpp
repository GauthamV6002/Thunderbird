#ifndef __WINGS
#define __WINGS

namespace thunderbird {
    class Wings {

        bool wingsAreOpen = false;
        
        public:
        void openWings();
        void closeWings();
        void runWings();

        void openLeft();
        void openRight();

        void closeLeft();
        void closeRight();
    };
}

#endif