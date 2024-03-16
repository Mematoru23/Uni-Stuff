package com.example.exam;

import configReader.ConfigReader;
import entity.Song;
import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import repositoryBin.RepoBin;
import service.Service;

import java.io.IOException;
import java.sql.SQLException;
import java.util.*;
import java.util.stream.Collectors;

public class HelloApplication extends Application {
    static Service<Song> ProdusService;

    @Override
    public void start(Stage stage) throws IOException, SQLException {

        VBox secondVerticalBox = new VBox();
        ListView<Song> ProdusListView = new ListView<>();
        ObservableList<Song> Produses = FXCollections.observableArrayList(ProdusService.getAll());
        ProdusListView.setItems(Produses);
        secondVerticalBox.getChildren().add(ProdusListView);

        GridPane ProdusGridPane = new GridPane();
        Label marcaLabel = new Label("marca");
        TextField marcaTextField = new TextField();
        Label numeLabel = new Label("nume");
        TextField numeField = new TextField();
        Label pretLabel = new Label("pret");
        TextField pretTextField = new TextField();
        Label cantitateLabel = new Label("cantitate");
        TextField cantitateField = new TextField();
        Label filtrareLabel = new Label("filtrare");
        TextField filtrareField = new TextField();

        ProdusGridPane.add(marcaLabel, 0, 1);
        ProdusGridPane.add(marcaTextField, 1, 1);
        ProdusGridPane.add(numeLabel, 0, 2);
        ProdusGridPane.add(numeField, 1, 2);
        ProdusGridPane.add(pretLabel, 0, 3);
        ProdusGridPane.add(pretTextField, 1, 3);
        ProdusGridPane.add(cantitateLabel, 0, 4);
        ProdusGridPane.add(cantitateField, 1, 4);
        ProdusGridPane.add(filtrareLabel, 0, 5);
        ProdusGridPane.add(filtrareField, 1, 5);
        secondVerticalBox.getChildren().add(ProdusGridPane);
        HBox ProdusActionsHorizontalBox = new HBox();
        Button addProdusButton = new Button("Add");
        Button filtrareProdusButton = new Button("Filtrare");
        Button filtrareProdusButton2 = new Button("Filtrare 2");
        ProdusActionsHorizontalBox.getChildren().add(addProdusButton);
        ProdusActionsHorizontalBox.getChildren().add(filtrareProdusButton);
        ProdusActionsHorizontalBox.getChildren().add(filtrareProdusButton2);
        secondVerticalBox.getChildren().add(ProdusActionsHorizontalBox);

        addProdusButton.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent mouseEvent) {
                try {
                    Integer id = 5;
                    String marca = marcaTextField.getText();
                    String nume = numeField.getText();
                    Double pret = Double.parseDouble(pretTextField.getText());
                    Integer cantitate = Integer.parseInt(cantitateField.getText());
                    Song Produs = new Song(id, marca, nume, pret, cantitate);
                    ProdusService.add(Produs);
                    Produses.setAll(ProdusService.getAll());
                } catch (Exception e) {
                    Alert alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("Error");
                    alert.setContentText(e.getMessage());
                    alert.show();

                    Scene scene = new Scene(secondVerticalBox, 320, 240);
                    stage.setTitle("Medical application!");
                    stage.setScene(scene);
                    stage.show();
                }
            }
        });
        filtrareProdusButton.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent mouseEvent) {
                VBox thirdVerticalBox = new VBox();
                ListView<String > filtrare1ListView = new ListView<>();
                ObservableList<String> filtrari1;

                try {
                    Collection<Song> produse =  ProdusService.getAll();
                    filtrari1 = FXCollections.observableArrayList(filtrare(produse, filtrareField.getText()));
                } catch (SQLException e) {
                    throw new RuntimeException(e);
                }
                filtrare1ListView.setItems(filtrari1);
                thirdVerticalBox.getChildren().add(filtrare1ListView);

                Stage stage = new Stage();
                stage.setTitle("My New Stage Title");
                stage.setScene(new Scene(thirdVerticalBox, 450, 450));
                stage.show();
            }
        });
        Tab tab2 = new Tab("Produs");
        tab2.setClosable(false);
        tab2.setContent(secondVerticalBox);

        secondVerticalBox.setPadding(new Insets(10, 10, 10, 10));


        VBox vBox = new VBox(secondVerticalBox);
        Scene tabs = new Scene(vBox);

        stage.setTitle("Hello!");
        stage.setScene(tabs);
        stage.show();
    }
    public ObservableList<String> filtrare(Collection<Song> produse, String sirDeCaractere) {

        return produse.stream()
                .filter(produs -> {
                    return produs.getTitle().toLowerCase().contains(sirDeCaractere.toLowerCase())
                            || produs.getBand().toLowerCase().contains(sirDeCaractere.toLowerCase());
                })
                .map(produs -> produs.getTitle() + " - " + produs.getBand())
                .collect(Collectors.toCollection(FXCollections::observableArrayList));
    }
    public static void main(String[] args) throws IOException, SQLException {
        ConfigReader configReader = new ConfigReader();
        Map<String,String> config = configReader.config();

        if(Objects.equals(config.get("Repository"), "binary")) {
            String element = config.get("Produs");
            RepoBin<Song> repoProdus = new RepoBin<Song> (element);
            ProdusService = new Service<Song>(repoProdus);
            launch();
        }
        else
            System.out.println("Repository ul nu exista");
    }
}