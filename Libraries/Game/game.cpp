int Game::init(){
	setLabyrinth();
    setSpeed();
    initscr();                   // Переход в curses-режим
    printw("Hello world!\n");  // Отображение приветствия в буфер
    refresh();                   // Вывод приветствия на настоящий экран
    getch();                     // Ожидание нажатия какой-либо клавиши пользователем
    endwin();                    // Выход из curses-режима. Обязательная команда.
}

int Game::run(){
	bool flag = 0;
	while(!flag){
        int iNewDestination = iDestination;
        
        if (_kbhit())
        {
            char cKey = _getch();
            printf("%d\n", cKey);

            switch (cKey)
            {
                case 119:
                    
                    iNewDestination = 1;
                    break;
                
                case 100:
                    
                    iNewDestination = 2;
                    break;
                
                case 115:
                    
                    iNewDestination = 3;
                    break;
                
                case 97:
                    
                    iNewDestination = 0;
                    break;
                    
                case 112:
                    
                    ChangeState(hConsole, scState, &iState);
                    while (1)
                    {
                        if (_kbhit())
                        {
                            char cKey = _getch();
                            
                            if (cKey == 99)
                            {
                                break;
                            }
                            else if (cKey == 115)
                            {
                                ChangeSpeed(hConsole, scSpeed, &iSpeed);
                            }
                        }
                        
                        Sleep(500);
                    }
                    
                    ChangeState(hConsole, scState, &iState);
                    break;
                    
                case 27:
                    
                    flag = 0;
                    break;
                 
            }
        }
        
        iFlag = !iFlag ? MoveSnakeSection(hConsole, scPosition, scBorderSize, &scBall, iSnake, &iSnakeLength, &iSnakeHead, &iDestination, iNewDestination, &iScore, scScore) : 1;
        Sleep(iSpeed);
	}
	return 0;
}

void Game::setLabyrinth(){

}

void Game::setSpeed(){

}