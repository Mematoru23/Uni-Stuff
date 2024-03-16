package Domain;

import java.util.Arrays;
import java.util.List;

public class OrderFactory implements IEntityFactory<Order>{
    @Override
    public Order createEntity(String line) {
        String[] parts = line.split(";");
        int id = Integer.parseInt(parts[0]);
        String[] cakes = new String[parts.length - 2];
        for(int i = 1; i < parts.length-1; i++){
            cakes[i - 1] = parts[i];
        }
        List<Cake> cakesList = Arrays.stream(cakes).map((cake) -> {
           String strId = cake.split(",")[0];
           int idCake = Integer.parseInt(strId);
           String cakeType = cake.split(",")[1];
           return new Cake(idCake,cakeType);
        }).toList();
        String date = parts[parts.length-1];

        return new Order(id, cakesList, date);
    }
}
