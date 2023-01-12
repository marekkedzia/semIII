package polymorphism.garbages;

public class GlassGarbage extends Garbage{
    private int volumeInCubicMilliliter;

    public GlassGarbage(int weightInGrams, int volumeInCubicMilliliter) {
        super(weightInGrams);
        if (volumeInCubicMilliliter <= 0)
            throw new Error("Volume must be positive Integer");

        this.volumeInCubicMilliliter = volumeInCubicMilliliter;
    }

    @Override
    public String toString() {
        return "GlassGarbage{" +
                "volumeInCubicMilliliter=" + volumeInCubicMilliliter +
                '}';
    }
}
