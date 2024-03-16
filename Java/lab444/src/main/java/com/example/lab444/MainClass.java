package com.example.lab444;

import Domain.*;
import com.example.lab444.GUI.HelloApplication;
import com.example.lab444.Repository.*;
import com.example.lab444.Service.CakeService;
import com.example.lab444.Service.OrderService;
import com.example.lab444.UI.Console;

import java.util.Objects;

public class MainClass {
    public static void main(String[] args){
        IEntityConverter<Cake> cakeConverter = new CakeConverter();
        IEntityConverter<Order> orderConverter = new OrderConverter();
        IRepository<Cake> repositoryCake= null;
        IRepository<Order> repositoryOrder = null;

        Settings setari = Settings.getInstance();
        if(Objects.equals(setari.getRepoType(), "database")){
            repositoryCake = new CakeDbRepository();
            repositoryOrder = new OrderDbRepository();
            ((CakeDbRepository) repositoryCake).openConnection();
            ((OrderDbRepository) repositoryOrder).openConnection();
            ((OrderDbRepository) repositoryOrder).insertRandomData(repositoryCake);

        }
        if (Objects.equals(setari.getRepoType(), "memory")) {
            repositoryCake = new MemoryRepository<>();
            repositoryOrder = new MemoryRepository<>();
        }
        if (Objects.equals(setari.getRepoType(), "text")){
            repositoryCake = new TextFileRepository<>(setari.getRepoCake(), cakeConverter);
            repositoryOrder = new TextFileRepository<>(setari.getRepoOrder(), orderConverter);
        }
        if (Objects.equals(setari.getRepoType(), "binary")){
            repositoryCake = new BinaryFileRepository<>(setari.getRepoCake());
            repositoryOrder = new BinaryFileRepository<>(setari.getRepoOrder());
        }

        CakeService cakeService = new CakeService(repositoryCake);
        OrderService orderService = new OrderService(repositoryOrder);
        Console console = new Console(cakeService,orderService );


        //console.runMenu();
        HelloApplication.main(args);
    }
}
