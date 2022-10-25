package se.liu.ida.tdde45.house;

import se.liu.ida.tdde45.food.ingredients.raw.RawEgg;
import se.liu.ida.tdde45.food.ingredients.raw.RawPotato;
import se.liu.ida.tdde45.food.ingredients.raw.Yoghurt;
import se.liu.ida.tdde45.singletons.FridgeStocker;
import se.liu.ida.tdde45.singletons.UninitializedSingletonException;

@SuppressWarnings("serial")
public class Fridge {
	private boolean stocked = false;
	private FridgeStocker fridgeStocker;

	public Fridge(FridgeStocker fridgeStocker) {
		this.fridgeStocker = fridgeStocker; 
	}
	
	public RawEgg getEgg() throws UnstockedException {
		if(!stocked)
			throw new UnstockedException();
		
		return new RawEgg();
	}
	
	public Yoghurt getYoghurt() throws UnstockedException {
		if(!stocked)
			throw new UnstockedException();

		return new Yoghurt();
	}
	
	public RawPotato getPotato() throws UnstockedException {
		if(!stocked)
			throw new UnstockedException();

		return new RawPotato();
	}

	public void stock() throws UninitializedSingletonException {
		fridgeStocker.stock(this);
		stocked = true;
		
	}

	public static class UnstockedException extends Exception {
		public UnstockedException() {
			super("Fridge has not been stocked!");
		}
	}
}
