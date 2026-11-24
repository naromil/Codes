public class FourSeven {

    private final int SEVEN = 7;
    private final double SIXTY = 0.60;
    private final int THOUSAND = 1000;

    public int predictGame(double team1Odds) {
        return (Math.random() < team1Odds) ? 1 : 2;
    }

    public int predictSeries() {
        int sum = -SEVEN;
        for (int i = 1; i <= SEVEN; i++)
            sum += predictGame(SIXTY);
        return (sum <= SEVEN / 2) ? 1 : 2;
    }

    public void main(String[] args) {
        int sum = -THOUSAND;
        for (int i = 1; i <= THOUSAND; i++) {
            sum += predictSeries();
        }
        sum = THOUSAND - sum;

        System.out.println("Team 1 Odds: " + (100.0 * sum / THOUSAND) + "%");
    }
}
