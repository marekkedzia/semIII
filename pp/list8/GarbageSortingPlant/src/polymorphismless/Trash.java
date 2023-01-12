package polymorphismless;

public class Trash {
    int weightInGrams;
    private int volumeInCubicMilliliter;
    private int grammage;
    private String materialType;
    private double crushedVolumeInCubicMillimeter;

    private boolean metallized = false;
    private final TrashType type;

    public Trash(TrashType type, int weightInGrams, double crushedVolumeInCubicMillimeter) {
        if (type != TrashType.GLASS)
            throw new Error("This type is incorrect. Found: " + type + ", required: " + TrashType.GLASS);
        if (weightInGrams <= 0 || crushedVolumeInCubicMillimeter <= 0)
            throw new Error("Parameters have to be positive Integer");

        this.type = type;
        this.weightInGrams = weightInGrams;
        this.crushedVolumeInCubicMillimeter = crushedVolumeInCubicMillimeter;
    }

    public Trash(TrashType type, int grammage, int weightInGrams) {
        if (type != TrashType.PAPER && type != TrashType.METALLIZED_PAPER)
            throw new Error("This type is incorrect. Found: " + type + ", required: " + TrashType.PAPER);

        if (weightInGrams <= 0)
            throw new Error("Weight must be positive Integer");

        this.type = type;
        this.weightInGrams = weightInGrams;
        this.grammage = grammage;
    }

    public Trash(TrashType type, String materialType, int weightInGrams, int volumeInCubicMilliliter) {
        if (type != TrashType.PLASTIC)
            throw new Error("This type is incorrect. Found: " + type + ", required: " + TrashType.PLASTIC);
        if (weightInGrams <= 0 || volumeInCubicMilliliter <= 0)
            throw new Error("Parameters have to be positive Integer");

        this.type = type;
        this.weightInGrams = weightInGrams;
        this.volumeInCubicMilliliter = volumeInCubicMilliliter;
        this.materialType = materialType;
    }

    @Override
    public String toString() {
        if (type == TrashType.PAPER)
            return "Garbage{" +
                    "weightInGrams=" + weightInGrams +
                    ", grammage=" + grammage +
                    ", type=" + type +
                    ", metallized=" + metallized +
                    '}';
        if (type == TrashType.GLASS)
            return "Garbage{" +
                    "weightInGrams=" + weightInGrams +
                    ", crushedVolumeInCubicMillimeter=" + crushedVolumeInCubicMillimeter +
                    ", type=" + type +
                    '}';
        if (type == TrashType.PLASTIC)
            return "Garbage{" +
                    "weightInGrams=" + weightInGrams +
                    ", volumeInCubicMilliliter=" + volumeInCubicMilliliter +
                    ", materialType='" + materialType + '\'' +
                    ", type=" + type +
                    '}';
        else
            throw new Error("Type is not assignable to GarbageType");
    }


    public boolean isMetallized() {
        return metallized;
    }

    public TrashType getType() {
        return type;
    }
}
