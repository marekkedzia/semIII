package polymorphism.garbages;

public class MetallizedPaperGarbage extends PaperGarbage {
    public MetallizedPaperGarbage(int weightInGrams, int grammage) {
        super(weightInGrams, grammage);
    }

    @Override
    public String toString() {
        return "MetallizedPaperGarbage{" +
                "weightInGrams=" + weightInGrams +
                "contains metal" +
                '}';
    }
}
