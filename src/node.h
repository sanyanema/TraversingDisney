// getter for wait time, latitude, long, name

class Node {
    public:
        Node();
        Node(int waitTime, double latitude, double longitude, std::string name);
        int getWaitTime();
        double getLatitude();
        double getLongitude();
        std::string getName();
    private:
        int waitTime;
        double latitude;
        double longitude;
        std::string name;
};