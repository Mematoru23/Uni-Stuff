package Domain;

import Domain.Entity;

import java.util.ArrayList;
import java.util.List;

public class Order extends Entity {
    List<Cake> orderCakes = new ArrayList<>();
    String date;

    public Order(int id, List<Cake> oc, String date) {
        super(id);
        orderCakes.addAll(oc);
        this.date = date;
    }

    public List<Cake> getOrderCakes() {
        return this.orderCakes;
    }

    public String getDate() {
        return this.date;
    }

    public void setOrderCakes(List<Cake> orderCakes) {
        this.orderCakes = orderCakes;
    }

    public void setDate(String date) {
        this.date = date;
    }

    @Override
    public String toString()
    {
        String ans = "";
        ans += this.id + ";";
        for (Cake c : this.orderCakes)
        {
            ans += String.format("%d,%s;", c.getId(), c.getCakeType());
        }
        ans += this.date;
        return ans;
    }
}
