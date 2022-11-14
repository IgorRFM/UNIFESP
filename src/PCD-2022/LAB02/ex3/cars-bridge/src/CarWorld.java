import java.awt.*;
import java.io.InputStream;
import java.util.*;
import java.util.concurrent.Semaphore;

import javax.swing.*;

class CarWorld extends JPanel {

	Image bridge;
	Image redCar;
	Image blueCar;

	TrafficController controller;

	ArrayList<Car> blueCars = new ArrayList<Car>();
	ArrayList<Car> redCars = new ArrayList<Car>();

	Semaphore sem = new Semaphore(1, true);

	public CarWorld() {
		controller = new TrafficController();
		MediaTracker mt = new MediaTracker(this);
		Toolkit toolkit = Toolkit.getDefaultToolkit();

		redCar = toolkit.getImage("src/image/redcar.gif");
		mt.addImage(redCar, 0);
		blueCar = toolkit.getImage("src/image/bluecar.gif");
		mt.addImage(blueCar, 1);
		bridge = toolkit.getImage("src/image/bridge1.gif");
		mt.addImage(bridge, 2);

		try {
			mt.waitForID(0);
			mt.waitForID(1);
			mt.waitForID(2);
		} catch (java.lang.InterruptedException e) {
			System.out.println("Couldn't load one of the images");
		}

		redCars.add(new Car(Car.REDCAR, null, redCar, null, sem));
		blueCars.add(new Car(Car.BLUECAR, null, blueCar, null, sem));
		setPreferredSize(new Dimension(bridge.getWidth(null), bridge.getHeight(null)));
	}

	public void paintComponent(Graphics g) {
		g.drawImage(bridge, 0, 0, this);
		for (Car c : redCars)
			c.draw(g);
		for (Car c : blueCars)
			c.draw(g);
	}

	public void addCar(final int cartype) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				Car c;
				if (cartype == Car.REDCAR) {
					c = new Car(cartype, redCars.get(redCars.size() - 1), redCar, controller, sem);
					redCars.add(c);
				} else {
					c = new Car(cartype, blueCars.get(blueCars.size() - 1), blueCar, controller, sem);
					blueCars.add(c);
				}
				new Thread(c).start();
			}
		});
	}

}
