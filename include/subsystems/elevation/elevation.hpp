#ifndef __ELEVATION
#define __ELEVATION

namespace thunderbird {
    class Elevation {
        public:

        bool elevationIsExpanded = false;
        
        void expandElevationMechanism();
        void retractElevationPiston();
        void toggleElevationMechanism();


        void runElevation();
    };
}

#endif