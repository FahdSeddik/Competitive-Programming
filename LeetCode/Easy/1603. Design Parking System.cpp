class ParkingSystem {
    int b,m,s;
public:
    ParkingSystem(int big, int medium, int small) {
        b=big,m=medium,s=small;
    }
    
    bool addCar(int carType) {
        switch(carType){
            case 1:return b==0 ? false:b--;
            case 2:return m==0 ? false:m--;
            default:return s==0 ? false:s--;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */