package polymorphismless;


import polymorphism.Sorter;

import java.util.ArrayList;

public class TrashSortingPlant implements Sorter<Trash> {
    private final ArrayList<Trash> plasticTrashes;
    private final ArrayList<Trash> glassTrashes;
    private final ArrayList<Trash> paperTrashes;
    private final ArrayList<Trash> metallizedPaperTrashes;
    public TrashSortingPlant() {
        this.plasticTrashes = new ArrayList<>();
        this.glassTrashes = new ArrayList<>();
        this.paperTrashes = new ArrayList<>();
        this.metallizedPaperTrashes = new ArrayList<>();
    }

    @Override
    public void sort(ArrayList<Trash> trashes) {
        for (Trash trash : trashes) {
            if (trash.getType() == TrashType.PAPER)
                if (trash.getType() == TrashType.METALLIZED_PAPER)
                    metallizedPaperTrashes.add(trash);
                else
                    paperTrashes.add(trash);
            if (trash.getType() == TrashType.GLASS)
                glassTrashes.add(trash);
            if (trash.getType() == TrashType.PLASTIC)
                plasticTrashes.add(trash);
        }
    }

    public ArrayList<Trash> getPlasticTrashes() {
        return plasticTrashes;
    }

    public ArrayList<Trash> getGlassTrashes() {
        return glassTrashes;
    }

    public ArrayList<Trash> getPaperTrashes() {
        return paperTrashes;
    }
}
