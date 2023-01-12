package polymorphism;

import polymorphism.garbages.*;

import java.util.ArrayList;

public class GarbageSortingPlant implements Sorter<Garbage> {
    private final ArrayList<PlasticGarbage> plasticGarbages;
    private final ArrayList<GlassGarbage> glassGarbages;
    private final ArrayList<PaperGarbage> paperGarbages;

    private final ArrayList<PaperGarbage> metallizedPaperGarbages;

    public GarbageSortingPlant() {
        this.plasticGarbages = new ArrayList<>();
        this.glassGarbages = new ArrayList<>();
        this.paperGarbages = new ArrayList<>();
        this.metallizedPaperGarbages = new ArrayList<>();
    }

    @Override
    public void sort(ArrayList<Garbage> garbages) {
        for (Garbage garbage : garbages) {
            if (garbage instanceof PlasticGarbage)
                plasticGarbages.add((PlasticGarbage) garbage);
            if (garbage instanceof GlassGarbage)
                glassGarbages.add((GlassGarbage) garbage);
            if (garbage instanceof PaperGarbage)
                if ( garbage instanceof MetallizedPaperGarbage)
                    metallizedPaperGarbages.add((PaperGarbage) garbage);
                else
                    paperGarbages.add((PaperGarbage) garbage);
        }
    }

    public ArrayList<PlasticGarbage> getPlasticGarbages() {
        return plasticGarbages;
    }

    public ArrayList<GlassGarbage> getGlassGarbages() {
        return glassGarbages;
    }

    public ArrayList<PaperGarbage> getPaperGarbages() {
        return paperGarbages;
    }
}
