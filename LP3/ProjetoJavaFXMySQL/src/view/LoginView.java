package view;

import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import model.Conexao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class LoginView {

    private Stage stage; // guardamos o stage para trocar de tela depois

    public LoginView(Stage stage) {
        this.stage = stage;
    }

    public void mostrarTela() {
        Label titulo = new Label("Tela de Login");
        titulo.setStyle("-fx-font-size: 18px; -fx-font-weight: bold;");

        Label labelUsuario = new Label("Usuário:");
        TextField campoUsuario = new TextField();

        Label labelSenha = new Label("Senha:");
        PasswordField campoSenha = new PasswordField();

        Button botaoLogin = new Button("Entrar");
        Button botaoCadastro = new Button("Ir para Cadastro");
        Label mensagem = new Label();

        botaoLogin.setOnAction(e -> {
            String nome = campoUsuario.getText();
            String senha = campoSenha.getText();

            if (autenticarUsuario(nome, senha)) {
                mensagem.setText("✅ Login realizado com sucesso!");
            } else {
                mensagem.setText("❌ Usuário ou senha incorretos.");
            }
        });

        // Ao clicar, troca para a tela de cadastro
        botaoCadastro.setOnAction(e -> {
            CadastroView cadastro = new CadastroView(stage);
            cadastro.mostrarTela();
        });

        VBox layout = new VBox(10, titulo, labelUsuario, campoUsuario, labelSenha, campoSenha, botaoLogin, botaoCadastro, mensagem);
        layout.setAlignment(Pos.CENTER);

        Scene cena = new Scene(layout, 350, 300);
        cena.getStylesheets().add(getClass().getResource("/css/estilo.css").toExternalForm());

        stage.setScene(cena);
        stage.setTitle("Login");
        stage.show();
    }

    private boolean autenticarUsuario(String nome, String senha) {
        String sql = "SELECT * FROM usuarios WHERE nome = ? AND senha = ?";

        try (Connection conn = Conexao.conectar();
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, nome);
            stmt.setString(2, senha);
            ResultSet rs = stmt.executeQuery();

            return rs.next();

        } catch (Exception e) {
            System.out.println("Erro ao autenticar: " + e.getMessage());
            return false;
        }
    }
}
