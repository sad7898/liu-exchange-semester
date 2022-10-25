package se.liu.ida.tdde45.mocks;

import se.liu.ida.tdde45.house.Fridge;
import se.liu.ida.tdde45.singletons.FridgeStocker;
import se.liu.ida.tdde45.singletons.UninitializedSingletonException;

public class MockFridgeStocker extends FridgeStocker{
    public MockFridgeStocker() {
        super();
    }
    @Override
    public void stock(Fridge fridge) throws UninitializedSingletonException {
   
    }
}
