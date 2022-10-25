package se.liu.ida.tdde45.singletons;

public class ChargingQueue {
	private static boolean initialized = false;
	private static BankConnector bc;
	
	public static void initialize(BankConnector b) {
		bc = b;
		initialized = true;
	}
	
	public static void enqueue() throws UninitializedSingletonException {
		if(!initialized)
			throw new UninitializedSingletonException(ChargingQueue.class);
		
		bc.withdraw();
	}
}
