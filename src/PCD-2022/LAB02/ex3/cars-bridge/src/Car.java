import java.awt.*;
import java.util.concurrent.Semaphore;

public class Car implements Runnable {
	private Semaphore sem;
	public static final int REDCAR = 0;
	public static final int BLUECAR = 1;

	private final static int bridgeY = 95;
	private final static int bridgeXLeft = 210;
	private final static int bridgeXLeft2 = 290;
	private final static int bridgeXMid = 410;
	private final static int bridgeXRight2 = 530;
	private final static int bridgeXRight = 610;
	private final static int totalWidth = 900;
	private final static int initX[] = { -80, totalWidth };
	private final static int initY[] = { 135, 55 };
	private final static int outLeft = -200;
	private final static int outRight = totalWidth + 200;

	int cartype;
	int xpos, ypos;
	Car inFront;
	Image image;
	TrafficController controller;

	public Car(int cartype, Car inFront, Image image, TrafficController controller, Semaphore sem) {
		this.cartype = cartype;
		this.inFront = inFront;
		this.image = image;
		this.controller = controller;
		this.sem = sem;

		if (cartype == REDCAR)
			xpos = inFront == null ? outRight : Math.min(initX[cartype], inFront.getX() - 90);
		else
			xpos = inFront == null ? outLeft : Math.max(initX[cartype], inFront.getX() + 90);
		ypos = initY[cartype];
	}

	public void move() {
		int xposOld = xpos;
		if (cartype == REDCAR) {

			if (inFront.getX() - xpos > 100) {
				xpos += 4;
				if (xpos >= bridgeXLeft & xposOld < bridgeXLeft)
					controller.enterLeft();
				else if (xpos > bridgeXLeft && xpos < bridgeXMid) {
					if (ypos > bridgeY)
						ypos -= 2;
				} else if (xpos >= bridgeXRight2 && xpos < bridgeXRight) {
					if (ypos < initY[REDCAR])
						ypos += 2;
				} else if (xpos >= bridgeXRight && xposOld < bridgeXRight)
					controller.leaveRight();
			}
		} else {
			if (xpos - inFront.getX() > 100) {
				xpos -= 4;
				if (xpos <= bridgeXRight && xposOld > bridgeXRight)
					controller.enterRight();
				else if (xpos < bridgeXRight && xpos > bridgeXMid) {
					if (ypos < bridgeY)
						ypos += 2;
				} else if (xpos <= bridgeXLeft2 && xpos > bridgeXLeft) {
					if (ypos > initY[BLUECAR])
						ypos -= 2;
				} else if (xpos <= bridgeXLeft && xposOld > bridgeXLeft)
					controller.leaveLeft();
			}
		}
	}

	public void run() {

		boolean outOfSight = cartype == REDCAR ? xpos > totalWidth : xpos < -80;
		boolean ponte = cartype == REDCAR ? xpos > bridgeXLeft : xpos < bridgeXRight;

		try {
			System.out.println("Permits: " + sem.availablePermits());
			// sem.acquire();

			System.out.println("SemAcquire " + cartype + " " + sem.availablePermits());
			while (!outOfSight) {
				System.out.println("Na ponte? " + ponte + "| (" + xpos + ")");
				// System.out.println("Outofsight: " + outOfSight + cartype);
				move();
				outOfSight = cartype == REDCAR ? xpos > totalWidth : xpos < -80;
				ponte = xpos > bridgeXLeft && xpos < bridgeXRight ? true : false;
				if (ponte) {
					sem.acquire();
					while (ponte) {
						System.out.println("Na ponte");
						ponte = xpos > bridgeXLeft && xpos < bridgeXRight ? true : false;
						move();
						try {
							Thread.sleep(10);
						} catch (InterruptedException e) {
						}
					}
					sem.release();
				}
				try {
					Thread.sleep(10);
				} catch (InterruptedException e) {
				}
			}
			System.out.println("SemRelease " + cartype + " " + sem.availablePermits());
			// sem.release();

		} catch (Exception e) {
			System.out.println(e);
		} finally {
		}

		xpos = cartype == REDCAR ? outRight : outLeft;
	}

	public int getX() {
		return xpos;
	}

	public void draw(Graphics g) {
		g.drawImage(image, xpos, ypos, null);
	}
}
