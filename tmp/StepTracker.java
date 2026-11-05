public class StepTracker {

    private final int baseline;

    private int steps, days, activeDays;

    public StepTracker(int baseline) {
        this.baseline = baseline;
    }

    public void addDailySteps(int step) {
        steps += step;
        days++;
        if (step >= baseline) {
            activeDays++;
        }
    }

    public int activeDays() {
        return activeDays;
    }

    public double averageSteps() {
        return days == 0 ? 0.0 : 1.0 * steps / days;
    }

    public static void main(String[] args) {
        StepTracker tr = new StepTracker(10000);

        System.out.println(tr.activeDays());
        System.out.println(tr.averageSteps());

        tr.addDailySteps(9000);
        tr.addDailySteps(5000);
        System.out.println(tr.activeDays());
        System.out.println(tr.averageSteps());

        tr.addDailySteps(13000);
        System.out.println(tr.activeDays());
        System.out.println(tr.averageSteps());

        tr.addDailySteps(23000);
        tr.addDailySteps(1111);
        System.out.println(tr.activeDays());
        System.out.println(tr.averageSteps());
    }
}
