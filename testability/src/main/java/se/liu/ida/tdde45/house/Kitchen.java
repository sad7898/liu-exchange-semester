package se.liu.ida.tdde45.house;

public class Kitchen {
	private final Stove stove = new Stove();
	private final Fridge fridge;
	private final Workbench workbench = new Workbench();

	public Kitchen (Fridge fridge){
		this.fridge = fridge;
	}
	
	public Stove getStove() {
		return stove;
	}
	
	public Fridge getFridge() {
		return fridge;
	}

	public Workbench getWorkbench() {
		return workbench;
	}
}
