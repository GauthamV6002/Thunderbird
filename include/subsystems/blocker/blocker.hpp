namespace thunderbird {
    class Blocker {
        public:

        bool blockerIsOpen = false;
        
        void openBlocker();
        void closeBlocker();
        void runBlocker();
    };
}