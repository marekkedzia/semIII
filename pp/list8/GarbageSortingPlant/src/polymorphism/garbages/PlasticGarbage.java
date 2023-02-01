package polymorphism.garbages;

public class PlasticGarbage extends Garbage {
    private final String materialType;
    private final double crushedVolumeInCubicMillimeter;
    public PlasticGarbage(int weightInGrams, String materialType, double crushedVolumeInCubicMillimeter) {
        super(weightInGrams);
        if (crushedVolumeInCubicMillimeter <= 0)
            throw new Error("Crushed volume must be positive Integer");
        this.materialType = materialType;
        this.crushedVolumeInCubicMillimeter = crushedVolumeInCubicMillimeter;
    }

    @Override
    public String toString() {
        return "polymorphism.garbages.PlasticGarbage{" +
                "materialType='" + materialType + '\'' +
                ", crushedVolumeInCubicMillimeter=" + crushedVolumeInCubicMillimeter +
                '}';
    }
}
