package Domain;

import Domain.Entity;

public class Cake extends Entity {
    private String cakeType;

    public Cake(int id, String cakeType) {
        super(id);
        this.cakeType = cakeType;
    }

    public String getCakeType() {
        return this.cakeType;
    }

    public void setCakeType(String cakeType) {
        this.cakeType = cakeType;
    }

    @Override
    public String toString()
    {
        return String.format("%d,%s", this.id, this.cakeType);
    }
}
