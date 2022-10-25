package se.liu.ida.tdde45.singletons;

import se.liu.ida.tdde45.house.Fridge;

public class FridgeStocker {
	private boolean initialized = false;
	public void initialize(){
		this.initialized = true;
	}
	public void stock(Fridge fridge) throws UninitializedSingletonException {
		if(!this.initialized)
			throw new UninitializedSingletonException(FridgeStocker.class);
		
		OrderDispatcher.order();
	}
}
