// dec 21 2014... DNA_DP is no longer an offset to DNA addresses... it's used to choose neurons
// to hook up to neuron 71 in either direction, now. Learning rule is the same... new synapse from
// random neuron if no firing of a neuron whose potential is also 0. Pull synapse on neuron that
// fires > 3 times
// has bidirectional synapses!

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// wow this one makes sound
// all the comments this program starts with are after these declares and function now
// sorry

// i also disabled the torus, edge-wrap, in this, stim, because i think
// something makes them usually flow down and right with it on. not sure
// i think there'll be more diversity if they're not all flowing around
// the torus mixing together, more diversity across the board, also drug
// spreading isn't done fairly so that it's fast and doesn't make it across
// the edges very well anyway so its more consistent to just turn them off,
// hahaha

// no i turned the torus back on and i'll add a key to toggle it soon actually

// >> look when you load a population with pgup their stun, sexctr and other values
//    are inherited from the state of the population's you loaded over. so, this
//    might send some delicate species into a crazy spin when loaded until you try
//    a few times or something, and, I will probably export these tables instead of
//    necrophiling them in the near future ok thanks. flamoot

// maybe make a motor to add drugs instead of or with the random drops // ok i did this
                                                                       // wish i had the idea scientology stole it seemed really ok
                                                                       // see below. scienitology is really bad
                                                                       // bye flamoot

// maybe make the drugs or a drug, mutagenic

// may be do some modulo thing to put the synapses off center so you see ones
// between cells on the same row that would be over each other. or just randomly
// offest it and let them shake aoround... 

// a neurons fired stat and view

// whats wrong with drug propagation

// stats for dna ops done

// if ohno < 4 give them 4-ohno as energy again ok

// maybe time each cell for a cost to keep it fast

// make poke and neuralnop make dna_ip by 4*opcodesPerFrame not 4
// well poke can skip it up to 7 instructions and maybe is fine dunno
// maybe i should make it up to 70

// add neuron and add synapse when brain or neuron is full should maybe
// do something anyway to keep dna from becoming ineffective when brain
// fills

// maybe grow synapses into the dna use the weight or plasticity factor
// as the high byte of the address and you can have a type that increments
// or decrements the byte at that address when the neuron fires. just synapses
// actually work the other direction so every byte of dna would need a synapse
// to do this really. ok not too sure there are other ways to do genetic write
// backs for long term memory etc [i used motors to do this see below]

// damn i had another idea it was important my brain implant made me forget it
// write it here if it ever comes back. it won't
// ok im so mad i lost that self mutation idea i'll just add another four
// cortical neurons there are 72 now with the drug one and, they'll do DNA
// self modification, one to increment/decrement a DP and one to inc/dec
// the byte at it, awesome. ok bye damn flamoot
// 76 cortical neurons then wow you'll want more than 100 (num_of_neurons)
// probably. i should start this run over but i'll keep trying this way for now

// great it says that now instead well. maybe lower the reward for common votes.
// google electronic dissolution of memory EDOM bye

// maybe have a way to make their soundreward array into a wave you'll have to
// use the step variable, look, i wish i had that other idea back it seemed too
// good to forget like that scientology is really happy right now they let me
// remember other things especially bad things my brain implant is rotten all
// the time and it's hard living this way wow flamoot bye
// ok maybe every display should be made into a sound if you want but you will
// have to use the wave step variable again bye flam

// give em a sensor if the DP is over an opcode (dont really want more cortical
// neurons or to check for multiples of 4 every frame, ah) or skip the DP over
// opcodes, or if you want to waste 3 more sensory neurons make inc/dec DP go
// a gene at a time and have motors to inc/dec opcode and each operand. oh that
// would take -six- more motors. ok so we'll see what i do about this. self-
// modification is just too dangerous if they can change opcodes... i think
// storing changes to dna as multiples of six as a rule would help them not
// destroy opcodes if they hit one. for instance, lol

// maybe keep them from removing the last remaining synapse on a neuron

Mix_Chunk *sound;
Mix_Chunk *soundBuffer;
Mix_Chunk *soundBuffer2;
Mix_Chunk *soundBuffer3;

Uint8 whichsound = 0;

char *targetWavFile = "/tmp/target.wav";

//void mcfcb2(int channel);
//void mcfcb3(int channel);

void mcfcb(Sint8 channel) { 
/*    int p;
    for (p=0; p < 256; p++) {
      if ((*soundBuffer).abuf[p] > 0 && (*soundBuffer).abuf[p] < 100 ) {
        printf("soundBuffer.abuf[%i] = %i\n", p, (*soundBuffer).abuf[p]);
      }
    }  */

//  printf("mcfcb. channel = %i\n", channel); 
//  SDL_Delay(1000);

    //printf("mcfcb: soundBuffer ");
//    Mix_ChannelFinished(NULL);
//    channel = Mix_PlayChannel(-1, soundBuffer3, 0);

//    SDL_Delay(0);

//    Mix_ChannelFinished(mcfcb2);
    if (whichsound == 1) {
    channel = Mix_PlayChannel(-1, soundBuffer, 0);

    whichsound = 2; } else {
    channel = Mix_PlayChannel(-1, soundBuffer2, 0);

    whichsound = 1; }

//    //printf("channel %i \n", channel);    
/*    if(channel < 0) {
      f//printf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
    }   */
  //printf ("1\n");
}


void sayview(int view) {
        if (view == 1) {printf ("generation view)\n");} else if (view == 2) {printf ("stunned view)\n");} else if (view == 3) {printf ("breed mood view)\n");} else if (view == 4) {printf ("DNA IP view)\n"); } else if (view == 5) {printf ("Gives view)\n");} else if (view == 6) {printf("Bites view)\n");} else if (view == 7) {printf("Pokes view)\n");} else if (view == 8) {printf("Fights view)\n");} else if (view == 9) {printf("NOP view)\n");} else if (view == 10) {printf("Neuron count view)\n");} else if (view == 11) {printf("Did Input view)\n");} else if (view == 12) {printf("BF Output view)\n");} else if (view == 13) {printf("Neural Skips/Stuns view)\n");} else if (view == 14) {printf("Sound reward view)\n");} else if (view == 15) {printf("stim view)\n");} else if (view == 16) {printf("self-modificatio view)\n");} else if (view == 17) {printf("DP/DNA_Length)\n");} else if (view == 99) { printf("Multi-view)\n"); }else {printf("\n");}
        return;
}
/*mcfcb2(int channel) { 
/*  int p;
    for (p=0; p < 256; p++) {
      if ((*soundBuffer2).abuf[p] > 0 && (*soundBuffer2).abuf[p] < 100) {
void sayview(int view) {
        if (view == 1) {printf ("generation view)\n");} else if (view == 2) {printf ("stunned view)\n");} else if (view == 3) {printf ("breed mood view)\n");} else if (view == 4) {printf ("DNA IP view)\n"); } else if (view == 5) {printf ("Gives view)\n");} else if (view == 6) {printf("Bites view)\n");} else if (view == 7) {printf("Pokes view)\n");} else if (view == 8) {printf("Fights view)\n");} else if (view == 9) {printf("NOP view)\n");} else if (view == 10) {printf("Neuron count view)\n");} else if (view == 11) {printf("Did Input view)\n");} else if (view == 12) {printf("BF Output view)\n");} else if (view == 13) {printf("Neural Skips/Stuns view)\n");} else if (view == 14) {printf("Sound reward view)\n");} else if (view == 15) {printf("stim view)\n");} else if (view == 16) {printf("self-modificatio view)\n");} else if (view == 17) {printf("DP/DNA_Length)\n");} else if (view == 99) { printf("Multi-view)\n"); }else {printf("\n");}
        return;
}
        printf("soundBuffer2.abuf[%i] = %i\n", p, (*soundBuffer2).abuf[p]);
      }
    }  */


//    Mix_ChannelFinished(NULL);
//  printf("mcfcb2. channel = %i\n", channel); 
//  SDL_Delay(1000);

    //printf("mcfcb2: soundBuffer2 ");
//    Mix_ChannelFinished(NULL);
//    channel = Mix_PlayChannel(-1, soundBuffer3, 0);

//    SDL_Delay(0);

//    Mix_ChannelFinished(mcfcb);
//    channel = Mix_PlayChannel(-1, soundBuffer2, 0);

//  whichsound = 1;

    ////printf("channel %i \n", channel);    
/*    if(channel < 0) {
      f//printf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
    }   */
  //printf ("2\n");
//}

//mcfcb3(int channel) {
//    Mix_ChannelFinished(NULL);
  //printf("mcfcb3. channel = %i\n", channel);
//  SDL_Delay(1000);
//    Mix_ChannelFinished(NULL);
//    channel = Mix_PlayChannel(-1, soundBuffer3, 0);
//    Mix_ChannelFinished(mcfcb);
//    channel = Mix_PlayChannel(-1, soundBuffer3, 0);
//printf ("3\n");
  
//}  // what

// adhoc changelog
// 4.99 -> 4.99.99: saveall/loadall added. last 4.xx ever
// 4.99 -> 4.99.9: changes to pull neuron/synapse reverted
// 4.98 -> 4.99: operand limit changed from num_of_neurons to 255. save/load fixed for windows build
// 4.97 -> 4.98: biteenergy quadrupled. import/export DNA IP
// 4.96 -> 4.97: removeneuron now pulls first synapse
// 4.95 -> 4.96: misc changes to neuron/synapse operations. windows version
// 4.93 -> 4.95: motors actuated on unchanging energy value so order is neutral
// 4.91 -> 4.93: give bonus raised from 1 to 3, fight difficulty raised to 1/8
// 4.?? -> 4.91: fixed a type/weight swap of low consequence
//               [type is 0 to 3, weight is 1 to 4] in add synapse; fight always used high
//               cell's energy, has been tweaked. 

// this is neural brainfuck version

// pre-calculate potential decay... it'd be faster

// they need a fifth directional sense, another 8 inputs, for neighbour temps

// make temperature affect decay... [done]

// gonna get in a tiled display of every view for the default view...

// make a lost fight only take energy from the attacker not the defender
// then remove this comment. well actually im not sure, i'll evolve longer
// then decide. it's only an issue for the neural version, pretty sure
// ok done it also removes more energy from the losing attacker than before,
// biteAmount * 1


// check plasticity, is it working? [yes] theres some debug outputs to get before im sure
// ok i looked at it they only went in one direction darn. should be better now
// the host neuron firing sends it the opposite way...

// maybe increment generation count by 1 on a mingle even without a mutation...
// oh just if the generations are different is better

// avggen is still wrong... wtf

// i'm starting children at the parent's IP right now...  search 'experiment' to
// find what you should change... if I don't reboot the DNA and clear the brains
// of children, i should save their brains when I save the DNA... which is kind
// of not a hassle anyway... ok

// recent fixes
// firing thresholds minimum is 1 or you get an FPE on the module by it
// which also makes neuron potentials over max carry over the remainder now
// but only the remainder it won't fire repeatedly from a very high synapse
// weight... or anything
// plasticity now pulls both ways
// synaps weight minimum is 1

// neural stuns should cost energy when they stun their dna penalize newcell

// maybe it should have a sensor to read off the dna. at DNA_DP. MAYBE

#define stimchance 54U   // per frame of time, high stims hitting a cell
#define stimdecay .99f  // stims level is times this per cell per stimdecevry
#define stimdecevry 5U   // yea decay stims every this many frames

#define num_of_neurons 180U // max 254, but leaving space will make args over
                            // num_of_neurons wrap to the first (cortical)
                            // neurons

#define num_of_synapses 242U // this is actually some weird constant which is
                           // the size of each neuron. it has to be two plus
                           // the number of synapses you want times four
// max neurons is 254, minimum is 66 (65 are permanent cortical neurons)
// thats 8 direction senses per 4 operations and one loud input out of
// 32 that shows temperature/energy with granularity of 8...
// 0 means unconnected so you get one less than that still

#define jitter_modifier -1.0f // ok set this to 1 or 0 or -1 if the sound
                              // rewards shake up and down check with V

#define cortical_neurons 91U // dont touch (2 for brainfuck program I/O) 

// heres a weird one
#define opcodesPerFrame 64U// wow 10 is a lot its,
                           // how many DNA instructions to evaluate in a turn
                           // for purposes of getting faster changes to the
                           // neural nets... in like this, the wave version,
                           // where they only have a half-dozen frames for
                           // the DNA to chop and screw the net in preparation
                           // for the next block of data, setting this to 5
                           // would mean they could run 30 opcodes between
                           // buifers. I might have it set to 10 or something
                           // eventually but that might not give them enough
                           // resolution...
#define neuralsubruns 3U // this is sort of the same thing it giv3s them
                         // this times the neural resolution over the sensory
                         // and motor one... it makes the fps like divided
                         // by this though and has other effects, think about
                         // it first. means the CA and DNA get to run only
                         // after each brain has done it this many times apiece
                         // note they have to neural nop for every neuralsubrun,
                         // not fire a motor for that long, for it to count as
                         // a neural nop, which aren't important anymore anyway
                         // but this is a bug and i'll get it fixed so any
                         // neural sub run spent nopping counts... hopefully
                         // some still-fast way

// fuck maybe when they flip over 255 (energy) i should breed them to a random square

// keys to let user toggle:
// dna phase
// ca phase
// breeding (opposed to splitting)

// get DNA loading in!

// CA is pretty hard so now gives add 1 energy, ok?

// views:
// actions (needs a new grid to store em)
// age? (add lifetime array then, too)
// sexiness (% operands > 8) * 2.55 < do this still
// skip counters
// generation count (highestgen-lowestgen)/((gen-lowestgen)+1)
// dna IP
//                 
// read how to set the palette
// why is avggen wrong
// have cell selection and ip in the dna view

// end old notes, start configurables

#define gridrows 32U //
#define gridcols 32U // weird plasma vortex w/ nature patterns
                     // (maybe not in neural version)
                     // you can go bigger but 80x80 fits into 1280x1024 real nice
                     // also change float DNA_View_Cell_Size_Divisor way under this if you change the sizes very much
                     // because cell sizes (when displayed) will also change...

//define gridrows 170
//define gridcols 213 // big ropes 

//define gridrows 68U  
//define gridcols 105U // rope. nice ratio. bumping rows toward 70 makes the bands
                     // more vertical


Uint16 popsize=gridcols*gridrows; //(gridrows*gridcols)
  
#define screenwidth 1024U
#define screenheight 768U

#define biteAmount 100U // energy moved per bite. this is also how much a give transfers
#define freeGiveBonus 120U // energy added on a give
                        // see if this is enough they can generate among
                        // relatives with gives if so
#define freeEnergyToOffspring 150U // who knows. 5/7/8 here is also nice

//#define DNA_Length 32768    // seeing if huge dna (8000 instructions) helps obviate the
                            // weird threshold smash crash in windows and wine for some
                            // reason
//#define DNA_Length 16384U // hm  (4000 instructions)
//#define DNA_Length 8192U // for the tiny brains (2000 instructions)
#define DNA_Length 12288U // little bigger (3000 instructions)
//#define DNA_Length 6144U // little smaller (1500 instructions)
//#define DNA_Length 4096U // (1000 instructions) if you go this small on windows
                           //                     in this the stim version you
                           //                     get weird crashes... maybe
                           //                     in wave and prior versions
                           //                     too, in win

#define mutantrate 6 // 1/n offspring will be mutated. minimum is 1 (100%)
#define remutaterate 254U // 249/n chance of repeat mutations
#define remutateratelow 252U
//#define remutaterate 128U // half the rate for 128b mutations of 4096b dna
//#define remutateratelow 127U
#define sexoperandpersistance 10U // frames of sim time (cumulative so 5 is high)
                                // brains do this now not dna but i dunno

#define max_breed_fairness 5U // number of allowed recursions, max 255

// many more configurables below... in main()


/*
 * Set the pixel at (x, y) to the given value
 * NOTE: The surface must be locked before calling this!
 */
void putpixel(SDL_Surface *surface, int x, int y, Uint8 pixel)
{
if (x < 0 || x >= screenwidth || y <0  || y >=screenheight) { return; }
//    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
//    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * 1;
                                                                       
//    switch(1) {
//    case 1:
        *p = pixel;
//        break;
        return;

/*    case 2:
        *(Uint16 *)p = pixel;
        break;
              
    case 3:   
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;
              
    case 4:   
        *(Uint32 *)p = pixel;
        break;
    }   */
}

void drawline(SDL_Surface *surface, Sint16 x, Sint16 y, Sint16 x2, Sint16 y2, Sint16 color, Sint16 endcolor) {
  Sint16 j = 0;
  Uint16 k = 0;
  float xdiff = 0;
  float ydiff = 0;
  float xstep;
  Uint16 xstart = 0;
  Uint16 ystart = 0;
  Uint16 xend = 0;
  Uint16 yend = 0;
  Uint16 i = 0;


/*  if (x>x2) {
    xdiff = x2 - x;
    xstart = x;
    xend = x2;
  } else {
    xdiff = x - x2;
    xstart = x;
    xend = x2;
  }
  if (y>y2) { 
    ydiff = y2 - y;
    ystart = y;
    yend = y2;
  } else { 
    ydiff = y - y2;
    ystart = y;    
    yend = y2;
  } */
  
  if (x2>x) { xstep = 1; } else { xstep = -1; }
  
  xstart = x;
  xend = x2;
  xdiff = (float) x2 - (float) x;
  
  ydiff = (float) y2 - (float) y;
  ystart = y;
  yend = y2;
  
  float ystep;
  if (xdiff != 0) {
    ystep = (float) ydiff / (float) xdiff;
    if (ystep > 0 && ydiff < 0) {
      ystep = 0-ystep;
    } else if (ystep < 0 && ydiff > 0) {
      ystep = -1.0f*ystep;
    }
  } else {
    ystep = ydiff;
  }
//  if (!ystep) {ystep = 0;} // nan protection
  float realy = 0;
  realy = (float) ystart;

  float realcolor = color;
  float colorstep;
  float ack;
  ack = xdiff;
  if (ack < 0) { ack = -1.0f*ack; }
  if (ydiff < 0) { ack -= ydiff; } else { ack += ydiff; }
  if (ack > 0) {
    colorstep = ((float) (endcolor - color)) / ack;
  } else { colorstep = 0; }

//    printf("xstart %i \tystart %i \txend %i \tyend %i \txdiff %f \tydiff %f \tystep %f \txstep %f \trealy %f \tj %i \ti %i \n", \
//            xstart,     ystart,     xend,     yend,     xdiff,     ydiff,     ystep,     xstep,     realy,     j,     i);


  float oldrealy = 0;
  unsigned int xctr = 0;
  if (xdiff < 0) { xdiff = -1.0f*xdiff; }  
  for (j = xstart; xctr <= xdiff; j+=xstep) {
    xctr+=1;
    oldrealy = realy;
    realy = realy + ystep;
    int p = 0;

    if (realy > oldrealy) {
      for (p = (Sint16) oldrealy; (Sint16) p <= (Sint16) realy; p++) {
//   printf("xstart %i \tystart %i \txend %i \tyend %i \txdiff %f \tydiff %f \tystep %f \txstep %f \trealy %f \tj %i \ti %i \tp %i \tcolorstep %f\trealcolor %f\n", \
//           xstart,     ystart,     xend,     yend,     xdiff,     ydiff,     ystep,     xstep,     realy,     j,     i,     p,     colorstep,    realcolor, 5);

        putpixel(surface, j, (unsigned int) p, (unsigned int) realcolor);
        realcolor += colorstep;
        if (p >= screenheight) {return;}
      }
    } else if (realy < oldrealy) {
      for (p = (Sint16) oldrealy; (Sint16) p >= (Sint16) realy; p--) {
//    if (p < 958) {
//    printf("xstart %i \tystart %i \txend %i \tyend %i \txdiff %f \tydiff %f \txstep %f \tystep %f \trealy %f \tj %i \ti %i \tp %i \n", \
//            xstart,     ystart,     xend,     yend,     xdiff,     ydiff,     xstep,     ystep,     realy,     j,     i,     p, 5);
//    }
        putpixel(surface, j, (unsigned int) p, (unsigned int) realcolor);
        realcolor += colorstep;
        if (p <= 0) { return; }
      }
    } else {
        putpixel(surface, j, (unsigned int) realy, (unsigned int) realcolor);
        realcolor += colorstep;
    }
  }
  
//  if ( SDL_MUSTLOCK(surface) ) {
//    SDL_UnlockSurface(surface);
//  }
//  printf("drawline done\n");
}

void black(SDL_Surface *surface) {  // clear screen
  int x;
  int y;
  for (x = 0; x < screenwidth; x++) {
    for (y = 0; y < screenheight; y++) {
      putpixel (surface, x, y, 0);
    }
  } 
}

void fillcell(SDL_Surface *surface, int cellw, int cellh, int x, int y, int xspace, int yspace, int xoff, int yoff, Uint8 color) {
  int xstart = ((cellw+xspace)*x)+xoff;
  int xend = ((cellw+xspace)*(x+1)-xspace)+xoff;
  int ystart = ((cellh+yspace)*y)+yoff;
  int yend = ((cellh+yspace)*(y+1)-yspace)+yoff;

  int j;
  int i;
  unsigned int randomdivisor = RAND_MAX>>8;
//  printf ("%i\n", color);

  for (j = ystart; j < yend; j++) {
    for (i = xstart; i < xend; i++) {
      putpixel(surface, i, j, color);
    }
  }

  if ( SDL_MUSTLOCK(surface) ) {
    SDL_UnlockSurface(surface);
  }
}

void drawgrid(SDL_Surface *surface, Uint8 **DNA, Uint8 neuroncount, Uint8 *didfire, Uint8 *grid, int drawgrid_gridrows, int drawgrid_gridcols, int cellw, int cellh, int xspace, int yspace, int drawgrid_screenwidth, int drawgrid_screenheight, float DNA_View_Cell_Size_Divisor, int drawgrid_DNA_Length, int view, int viewdata1, int viewdata2, int * viewdata3, Uint8 * viewdata4, int gridOffsetX, int gridOffsetY, Uint8 drawgrid, Uint8 drawdna) { 
  int i; int j;
  if (drawgrid) {
  for (i = 0; i < drawgrid_gridrows; i++) {
    for (j = 0; j < drawgrid_gridcols; j++) {
//      printf ("draw %i,%i,%i",i,j,*grid);
      if (view == 0) {
        fillcell(surface, cellw, cellh, j, i, xspace, yspace, gridOffsetX, gridOffsetY, *grid);
        grid += 1;
      } else if (view > 0) { // generations, stuns
        int c;
        if (view == 1 || view == 4 || view == 17) { // integer tables
          c = (255U*(((float)(*viewdata3)-(float)viewdata1)/(((float)viewdata2-(float)viewdata1)+1.0f)));
          viewdata3 += 1;
        } else if (view == 2 || view == 3 || (view >= 5 && view <= 16)) { // uint8 tables
          c = (255U*(((float)(*viewdata4)-(float)viewdata1)/(((float)viewdata2-(float)viewdata1)+1.0f)));
          viewdata4 += 1;
        }
        if (c > 255) { c = 255; }
        // if (view == 2 && c > 0) { printf ("graph individual of stun count %i as color %i. low = %i high = %i \n", *viewdata4, c, viewdata1, viewdata2); }
        fillcell(surface, cellw, cellh, j, i, xspace, yspace, gridOffsetX, gridOffsetY, c);

      }
    }
  }
  }
  if (drawdna == 1) { // draw synapses (2 will mean draw dna like old versions do)
//  int t = drawgrid_DNA_Length/((drawgrid_gridcols*DNA_View_Cell_Size_Divisor)-3)+1;
  int t = num_of_neurons/((drawgrid_gridcols*DNA_View_Cell_Size_Divisor)-0)+1;
  //    ^ 254 == num_of_neurons

  int dnactr = 1;
  for (i = drawgrid_gridrows; i < drawgrid_gridrows+t; i++) { 
    for (j = 0; j < (drawgrid_gridcols*DNA_View_Cell_Size_Divisor)-0; j++)  {
      fillcell(surface, ((float)(cellw/DNA_View_Cell_Size_Divisor))+xspace+1, ((float)(cellh/DNA_View_Cell_Size_Divisor))+yspace+1, j, i-drawgrid_gridrows, 0, 0, 0, (drawgrid_gridrows)*(cellh+yspace), 0);
      dnactr += 1;
    }
    if (dnactr > num_of_neurons) { break; } // num_of_neurons
  }

  dnactr=1;
  Uint8 *somedna = *DNA;
  int coords[num_of_neurons][2];
  for (i = drawgrid_gridrows; i < drawgrid_gridrows+t; i++) { 
//    printf("drawgrid_gridcols=%i\nDNA_View_Cell_Size_Divisor=%f\ndrawgrid_gridcols*DNA_View_Cell_Size_Divisor=%f\n",drawgrid_gridcols,DNA_View_Cell_Size_Divisor,(float) ((float) drawgrid_gridcols* (float)DNA_View_Cell_Size_Divisor));
    for (j = 0; j < (drawgrid_gridcols*DNA_View_Cell_Size_Divisor)-0; j++) {
//      printf("debug: draw dna %i,%i\n", j, i-drawgrid_gridrows);
      somedna+=num_of_synapses; // num_of_synapses
//      somedna += 1;
      coords[dnactr][0] = ((cellw/DNA_View_Cell_Size_Divisor+xspace)*j)+(cellw/DNA_View_Cell_Size_Divisor)/2;
      coords[dnactr][1] = ( ((drawgrid_gridrows+0)*(cellh+yspace)) + ( (i-drawgrid_gridrows) * ((cellh/DNA_View_Cell_Size_Divisor)+yspace) ) )+((cellh/DNA_View_Cell_Size_Divisor)/2);
//      if (dnactr < 3) {
//          printf("dnactr %i\ncoords[dnactr][0] set to %i\ncoords[dnactr][1] set to %i\n",dnactr,coords[dnactr][0],coords[dnactr][1]);
//      }


      if (dnactr < neuroncount && *(somedna+1) > 0 && *somedna > 0) {
          fillcell(surface, cellw/DNA_View_Cell_Size_Divisor, cellh/DNA_View_Cell_Size_Divisor, j, i-drawgrid_gridrows, xspace, yspace, 0, (drawgrid_gridrows)*(cellh+yspace), 32*((*(somedna+1)) / *somedna));
//          printf("cellw %i\ncellh %i\nDNA_View_Cell_Size_Divisor %i\ndrawgrid_gridrows %i\ni %i\nj %i\n",cellw,cellh,DNA_View_Cell_Size_Divisor,drawgrid_gridrows,i,j);

      } else {
        fillcell(surface, cellw/DNA_View_Cell_Size_Divisor, cellh/DNA_View_Cell_Size_Divisor, j, i-drawgrid_gridrows, xspace, yspace, 0, (drawgrid_gridrows)*(cellh+yspace), 0);
      }

      dnactr++;
//      if (dnactr >= drawgrid_DNA_Length) { break; }
      if (dnactr > num_of_neurons) { break; } // num_of_neurons
    }
//    if (dnactr >= drawgrid_DNA_Length) { break; }
    if (dnactr > num_of_neurons) { break; }
  }

//  printf("sniff out win crash draw synapse start\n");

  dnactr = 1;
  Uint8 *abrain = *DNA;
  for (i = drawgrid_gridrows; i < drawgrid_gridrows+t; i++) { 
    for (j = 0; j < (drawgrid_gridcols*DNA_View_Cell_Size_Divisor)-0; j++) {
      abrain += num_of_synapses;
//      printf("neuron %i, pot %i, thresh %i\n", dnactr, abrain[0], abrain[1]);
      int neur_offs = 2;
      while (neur_offs < num_of_synapses) { // christ
        Uint8 ab = abrain[neur_offs];
        if (ab == 0) { break; } // end of neuron

//        printf("dna_ctr %i\nneur_offs %i\ncoords[dnactr][0] is %i\ncoords[dnactr][1] is %i\nabrain[neur_offs] = %i\ncoords[abrain[neur_offs]][0] is %i\ncoords[abrain[neur_offs]][1] is %i\n", dnactr, neur_offs, coords[dnactr][0], coords[dnactr][1], abrain[neur_offs], coords[abrain[neur_offs]][0], coords[abrain[neur_offs]][1] );
//        printf("df = %i\n", didfire[abrain[neur_offs]]);
//      printf("synapse, neur_offs = %i ", neur_offs);
//      printf("synapse, abrain[neur_offs] = %i ", abrain[neur_offs]);
//      printf("synapse, didfire[abrain[neur_offs]] = %i\n", didfire[abrain[neur_offs]]);
        if (didfire[ab]) {
//        if (didfire[0]) {
//          printf("novs\n");
          drawline(surface, coords[dnactr][0], coords[dnactr][1], coords[ab][0], coords[ab][1], 0, 40);
        }
        neur_offs += 4;
      }
      dnactr++;
      if (dnactr >= num_of_neurons) { break; } // num_of_neurons
    }
//    if (dnactr >= drawgrid_DNA_Length) { break; }
  if (dnactr >= num_of_neurons) { break; }
  }  
  }

//  printf("sniff out win crash draw synapse finish\n");

  /* Update just the part of the display that we've changed */
//  SDL_UpdateRect(surface, 0, 0, drawgrid_screenwidth-1, drawgrid_screenheight-1);
// do this after calling drawgrid in main() now since we call it many times
// sometimes, to draw mini-grids for multi-view
 
}

void loadcrit(int dnalength, int popsize, Uint8 **DNA, Uint8 **Brains, Uint8 *neuroncount, unsigned int *DNA_IP, unsigned int *DNA_DP, unsigned int *generations, char *fn, char *brainfile) {
  // i should load their dna_ip too in neural version in case starting at
  // 0 mangles the brains although they should be able to deal with that
  // when evolved... (ok)
  int i; int j;
  int q = (rand())%4;
  Uint8 loaddna[dnalength];
  Uint8 loadbrain[(num_of_neurons+1)*num_of_synapses];
  printf("Attempting to load DNA from ./ca-ga.load.dna and brain from ./ca-ga.load.brain because this is neural version\n");
  FILE*iff=fopen(fn,"rb");
  if (iff == NULL) {
    printf("puke (no such dna file)\n");
    return;
  }
  unsigned int loadedgeneration = 0;
  unsigned int loadeesdnaip = 0;
  unsigned int loadeesdnadp = 0;
  loadedgeneration = (Sint16) getc(iff)*16777216;
  loadedgeneration+= (Sint16) getc(iff)*65536;
  loadedgeneration+= (Sint16) getc(iff)*256;
  loadedgeneration+= (Sint16) getc(iff);
  loadeesdnaip = (Sint16) getc(iff)*256;
  loadeesdnaip+= (Sint16) getc(iff);
  for (i = 0; i < dnalength; i++) {
    loaddna[i] = getc(iff);
  }
  fclose(iff);
  Uint8 loadedneuroncount = 0;
  iff=fopen(brainfile,"rb");
  if (iff == NULL) {
    printf("puke (no such brain file)\n");
    return;
  }

  loadedneuroncount = getc(iff);
  for (i = 0; i < (num_of_neurons+1)*num_of_synapses; i++) {
    loadbrain[i] = getc(iff);
  }
  fclose(iff);
  printf( "DNA loaded\n");
  int many = 0;
  for (i = 0; i < popsize; i++) {
    q++;
    if (q == 4) {
//      printf("Load one to pop offset #%i\n", i);
      q = 0;
      *generations = loadedgeneration;
      *DNA_IP = loadeesdnaip;
      *DNA_DP = loadeesdnadp;
      Uint8 *somedna = *DNA;
      for (j=0;j<dnalength;j++) {
  //      *DNA = loaddna[j];
  //      DNA++;
        somedna[j] = loaddna[j];
      }
      *neuroncount = loadedneuroncount;
      Uint8 *somebrain = *Brains;
      for (j=0;j<(num_of_neurons+1)*num_of_synapses;j++) {
        somebrain[j] = loadbrain[j];
      }
      many++;
      DNA++;
      Brains++;
    } else {
  //    DNA+=dnalength;
      DNA++;
      Brains++;
    }
    generations++;
    neuroncount++;
    DNA_IP++;
    DNA_DP++;
  }
  printf("Loaded DNA & brain copied to %i/%i cells\n", many, popsize);
}

void savecrit(int generation, int dnalength, int popsize, Uint8 **DNA, Uint8 **Brains, Uint8 *neuroncount, unsigned int *DNA_IP, unsigned int *DNA_DP, unsigned int *generations, char *fn, char *brainfile) {
  // save dna_ip too
  printf ("Finding a critter of generation #%i to export to %s\n", generation, fn);

  unsigned int soughtgen;
  int offs = 0;
  for (soughtgen = generation; soughtgen > 0; soughtgen--) {
    while (*generations != soughtgen && offs < popsize) {
      //printf("debug: skipping animal of gen %i not of %i\n", *generations, soughtgen);
      generations++;
      offs++;
      neuroncount++;
	DNA_IP++;
	DNA_DP++;
    }
    if (offs >= popsize) { generations-=popsize; neuroncount -= popsize; DNA_IP -= popsize; DNA_DP -= popsize; offs = 0; } else {break;}// hm 
  }

  if (soughtgen>0) {

//    DNA+=(dnalength*offs); pre malloc?
    DNA+=offs;
    Uint8 *somedna = *DNA;
    Brains += offs;
    Uint8 *somebrain = *Brains; // hopefully it is the same brain

    printf ("Succeeds at population offset %i with critter of generation #%i\n", offs, soughtgen);
    int c;
    printf ("Write DNA ... ");
    FILE*of=fopen(fn,"wb");
    int g;
    int h;
    g = *generations;
    h = g/16777216;
    putc( (h), of);
    g -= h*16777216;
    h = g/65536;
    putc( (h), of);
    g -= h*65536;
    h = g/256;
    putc( (h), of);
    g -= 256*h;
    h = g%256;
    putc( (h), of); //or what 
//    putc((char) (*generations/ 256), of);
//    putc((char) (*generations% 256), of); //or what 
    putc((char) (*DNA_IP/ 256), of);
    putc((char) (*DNA_IP% 256), of); //or what 
    putc((char) (*DNA_DP/ 256), of);
    putc((char) (*DNA_DP% 256), of); // ok
    for (c = 0; c < dnalength; c++) {
      putc((char) somedna[c], of);
//      DNA++;
    }
    fclose(of);
    printf ("succeeded\n");
    printf ("Write brain ... ");
    of=fopen(brainfile,"wb");
    putc((char) *neuroncount, of);
    for (c = 0; c < (num_of_neurons+1)*num_of_synapses; c++) {
      putc((char) somebrain[c], of);
//      DNA++;
    }
    fclose(of);
    printf ("succeeded\n");
  } else {
    printf ("wtf i couldn't find any DNA over generation -1\n");
  }

}

void loadall(int dnalength, int popsize, Uint8 **DNA, Uint8 **Brains, Uint8 *neuroncount, unsigned int *DNA_IP, unsigned int *DNA_DP, unsigned int *generations, char *fn, char *brainfile) {
  // i should load their dna_ip too in neural version in case starting at
  // 0 mangles the brains although they should be able to deal with that
  // when evolved... (ok)
  int i; int j;
  Uint8 loaddna[dnalength];
  Uint8 loadbrain[(num_of_neurons+1)*num_of_synapses];
  int many = 0;
  printf("Attempting to load DNA from %s and brain from %s because this is neural version\n", fn, brainfile);
  FILE*iff=fopen(fn,"rb");
  if (iff == NULL) {
    printf("puke (no such dna file)\n");
    return;
  }

  FILE*biff=fopen(brainfile,"rb");
  if (biff == NULL) {
    printf("puke (no such brain file)\n");
    return;
  }

  unsigned int loadedgeneration = 0;
  unsigned int loadeesdnaip = 0;
  unsigned int loadeesdnadp = 0;
  for (i = 0; i < popsize; i++) {
        loadedgeneration = (Sint16) getc(iff)*16777216;
        loadedgeneration+= (Sint16) getc(iff)*65536;
	loadedgeneration+= (Sint16) getc(iff)*256;
	loadedgeneration+= (Sint16) getc(iff);
	loadeesdnaip = (Sint16) getc(iff)*256;
	loadeesdnaip+= (Sint16) getc(iff);
	loadeesdnadp = (Sint16) getc(iff)*256;
	loadeesdnadp+= (Sint16) getc(iff);
	for (j = 0; j < dnalength; j++) {
	  loaddna[j] = getc(iff);
	}
	Uint8 loadedneuroncount = 0;
	loadedneuroncount = getc(biff);
	for (j = 0; j < (num_of_neurons+1)*num_of_synapses; j++) {
	  loadbrain[j] = getc(biff);
	}
      printf("generation %i neuroncount %i DNA_IP %i DNA_DP %i pop offset #%i\n", loadedgeneration, loadedneuroncount, loadeesdnaip, loadeesdnadp, i);

//      if (i>1800){return;} // for load small pop and oops delete this

      *generations = loadedgeneration;
      *DNA_IP = loadeesdnaip;
      *DNA_DP = loadeesdnadp;
      Uint8 *somedna = *DNA;
      for (j=0;j<dnalength;j++) {
        somedna[j] = loaddna[j];
      }
      *neuroncount = loadedneuroncount;
      Uint8 *somebrain = *Brains;
      for (j=0;j<(num_of_neurons+1)*num_of_synapses;j++) {
        somebrain[j] = loadbrain[j];
      }
      many++;
      DNA++;
      Brains++;
      generations++;
      neuroncount++;
      DNA_IP++;
      DNA_DP++;
  }
  fclose(iff);
  fclose(biff);
  printf("Loaded DNA's & brains copied to %i/%i cells\n", many, popsize);
}

void saveall(int dnalength, int popsize, Uint8 **DNA, Uint8 **Brains, Uint8 *neuroncount, unsigned int *DNA_IP, unsigned int *DNA_DP, unsigned int *generations, char *fn, char *brainfile) {
  // save dna_ip too
  printf ("Exporting population to %s\n", fn);

  FILE*df=fopen(fn,"wb");
  FILE*bf=fopen(brainfile,"wb");

  int offs;
  for (offs=0; offs < popsize; offs++) {
    Uint8 *somedna = *DNA;
    Uint8 *somebrain = *Brains;

    printf ("Write DNA #%i of generation #%i at DNA_IP %i\n", offs, *generations, *DNA_IP);
    int c;
    int g;
    int h;
    g = *generations;
    h = g/16777216;
    putc( (h), df);
    g -= h*16777216;
    h = g/65536;
    putc( (h), df);
    g -= h*65536;
    h = g/256;
    putc( (h), df);
    g -= 256*h;
    h = g%256;
    putc( (h), df); //or what 
    putc( (*DNA_IP/256), df);
    putc( (*DNA_IP%256), df); //or what 
    putc( (*DNA_DP/256), df);
    putc( (*DNA_DP%256), df); //ok

    for (c = 0; c < dnalength; c++) {
      putc( somedna[c], df);
//      DNA++;
    }

    printf ("succeeded\n");
    printf ("Write brain (%i neurons)... ", *neuroncount);
    putc( *neuroncount, bf);
    for (c = 0; c < (num_of_neurons+1)*num_of_synapses; c++) {
      putc( somebrain[c], bf);
//      DNA++;
    }
    printf ("succeeded\n");

    DNA++;
    Brains++;
    generations++;
    neuroncount++;
    DNA_IP++;
    DNA_DP++;
  }
  fclose(bf);
  fclose(df);
}


int recursive_fair_breed(Uint8 source_x, Uint8 source_y, Uint8 dest_x, Uint8 dest_y, Uint8 x_3, Uint8 y_3, Uint8 offspring[gridcols][gridrows][17], Uint8 **DNA[gridcols][gridrows], Uint8 **Brains[gridcols][gridrows], Uint8 neuroncount[gridcols][gridrows], unsigned int generations[gridcols][gridrows], Uint8 sexctr[gridcols][gridrows], Uint8 skips[gridcols][gridrows], unsigned int DNA_IP[gridcols][gridrows], unsigned int DNA_DP[gridcols][gridrows], Uint8 dnarun_add[gridcols][gridrows], unsigned int *breeds, unsigned int *splits, unsigned int *maxIP, Uint8 sex_on, Uint8 recurse) {
  // note i don't really need a function for breeding it's probably faster
  // in main(). i just needed recursion well i thought i did, i couldn't
  // think of a code block that could recurse other than a function, but
  // i really only needed a stack... an array max_breed_fairness long
  // to store the offsets i'm considering would let me just loop over
  // it another way in main. so i'll probably move this code back there
  // ok?
  unsigned int randomdivisor = RAND_MAX>>8;
  unsigned int c;
//  Uint8 *somedna = DNA[source_x][source_y];
  
  recurse += 1;
  
//  printf ("recursive_fair_breed(start)\n");

  if (offspring[dest_x][dest_y][0] > 0) {
    // not safe to breed yet. recurse
   Uint8 offsidx;
   for (offsidx = 1; offsidx < offspring[dest_x][dest_y][0]; offsidx += 2) {
    if (x_3 != 255 && (dest_x == x_3 && dest_y == y_3)) {
//      printf("recurse: Three cells trying to loop the recurser. Prioritizing the first\n");
    } else if ((offspring[dest_x][dest_y][offsidx] == source_x && offspring[dest_y][dest_x][offsidx+1] == source_y) ) {
//      printf("recurse: Two cells trying to overwrite each other, prioritizing the first\n");
// would be better to do the swap they want rather than cancel the second or
// third breeder in the loop... but how
    } else { // could still get stuck on loops of 3 or more cells so. use a
             // max recursion, max_breed_fairness !
      if (recurse <= max_breed_fairness) {
//        printf("recurse: recursive_fair_breed(source_x=%i source_y=%i dest_x=%i dest_y=%i)\n", dest_x, dest_y, offspring[dest_x][dest_y][offsidx], offspring[dest_x][dest_y][offsidx+1]);
        recurse = recursive_fair_breed(dest_x, dest_y, offspring[dest_x][dest_y][offsidx], offspring[dest_x][dest_y][offsidx+1], source_x, source_y, offspring, DNA, Brains, neuroncount, generations, sexctr, skips, DNA_IP, DNA_DP, dnarun_add, breeds, splits, maxIP, sex_on, recurse);
//        printf("recurse: comes back after recurse of %i\n", recurse);
      } else { } // printf("recurse: recursed too deep\n"); } 
    }
   }
   offspring[dest_x][dest_y][0] = 0; 
  }
  

  // fall thru  
                  Uint8 *thisdna = (Uint8 *) DNA[source_x][source_y];
                  dnarun_add[dest_x][dest_y] += freeEnergyToOffspring; // recolor
                  int lastip = DNA_IP[dest_x][dest_y];
                  if (lastip > *maxIP) { *maxIP = lastip; }
//                  DNA_IP[dest_x][dest_y] = 0; // reboot
                  DNA_IP[dest_x][dest_y] = DNA_IP[source_x][source_y]; // kickstart (experimental)
                  DNA_DP[dest_x][dest_y] = DNA_DP[source_x][source_y];
                  sexctr[dest_x][dest_y] = 0;
                  skips[dest_x][dest_y] = 0;
                  int mutant = (rand()) % mutantrate; // n% are mutants
//                  int mutant = 1000;

                  //breedorsplit = (rand()/randomdivisor) % 2; // half the time breed
                                                    // half the time split


                  if (sexctr[source_x][source_y]>0 && sex_on) { // mingle (slow!)
//                    printf ("mingle\n");
                    if (generations[dest_x][dest_y] != generations[source_x][source_y]) {
                      generations[dest_x][dest_y] = ((generations[source_x][source_y] + generations[dest_x][dest_y])>>1)+1; // same generation dont increment..
                    }
                    *breeds += 1;
                    int r = 0;
                    char b = (rand()/randomdivisor);
//                    printf ("init newdna\n");
                    Uint8 *newdna = (Uint8 *) DNA[dest_x][dest_y];
//                    printf ("newdna init'd\n");
                    for (c = 0; c < DNA_Length; c++) {
                      if (b&1) { // parent
// WINDOWS V REENABLE
                        newdna[c] = thisdna[c];
//                        printf ("2\n");
                      } // else {
                        // DNA[destx][desty][c] = thisdna[c];
                        // keeps its own byte
//                        printf ("1\n");
//                      } 
                      }
                      b>>1;
                      r++;
                      if (r == 8) { r = 0; b = (rand()/randomdivisor); }

                  } else  { // split
//                    printf ("3\n");
//                    printf ("split\n");
                    generations[dest_x][dest_y] = generations[source_x][source_y];
                    *splits += 1;
//                    printf ("init newdna\n");
                    Uint8 *newdna = (Uint8 *) DNA[dest_x][dest_y];
//                    printf ("newdna init'd\n");
                    for (c = 0; c < DNA_Length; c++) {
// WINDOWS V REENABLE
                      newdna[c] = thisdna[c];
                    }
                  }




                  if (mutant == 0) {
//                    printf("mutate\n");
                    generations[dest_x][dest_y]+=1000; // self-mod adds 1
                    int maxoffset;
//                    if ((rand())>(RAND_MAX>>1)) { // bias


/*                      if (lastip>DNA_Length) {lastip=DNA_Length-4;}  */
                                                                // use this for a mutation bias
                                                                // when rebooting new cells at
                                                                // DNA_IP 0... if you resume
                                                                // at the parents IP in the
                                                                // child like i'm experimenting
                                                                // with, set lastip to DNA_Length
                                                                // like the line below
                      lastip = DNA_Length-4;
                      maxoffset = (lastip>>2)+1;  // last op

//                    } else { // dont
//                      maxoffset = (DNA_Length_div_two);
//                    } // trying if i always bias. this is only bad when
                        // IP's start hitting max and rolling over. using
                        // a table of lifespans to decide what offset if
                        // any to mutate under would be superior to this,
                        // for when that happens. otherwise biasing half
                        // the time i think is an expensive hack
                    int first = 1;
                    int oporarg = (rand())%4; // damn a whole byte of randomness for this
                    int limit;                                // ^ this is ok now
//                    if (oporarg > 0) { limit = 256; } else { limit = 6; }
                    limit = 256; // we'll always use 8 bits now and just modulo
                                 // opcode values over 5, for self-modification,
                                 // to be easier, for me. not for the cells as
                                 // such. though this biases the opcodes slightly
                                 // at the end where you get the remainder or
                                 // whatever. from 256/6. anyway its gonna be ok
                    while (((rand())%remutaterate < remutateratelow) || first) {
                      first = 0;
//                      int offset = ( ( ( (Sint16)(rand()/randomdivisor) )*256 )+(Sint16)(rand()/randomdivisor) ) % (DNA_Length/2);
// as long as all mutations reboot you we can just mutate bytes up to the
// highest IP this cell has reached yet and get more useful mutations in
// cold parts of the world that way
                  // it's not the destination's DNA we use after a kill
                  // unless it was a breed. but i think collecting mutations
                  // to under the IP of the dead cell about half the time
                  // say, will make species faster and promote strategies
                  // to live long to preserve early genetic material. only
                  // problem is critters who live to the end of the genome
                  // and loop will still only get mutated under the point
                  // where they died in spite of having run the whole thing
                  // unless i had a table for ones that had or an extra
                  // check here so i'll just do it half the time instead
                  // kind of a bias. well it looks good in practice tbh
                      int offset = ( ( ( (unsigned int)(rand()) ))) % (maxoffset);
                      int c = ((rand())%limit);
// WINDOWS V REENABLE
                      thisdna[offset*4 + oporarg] = c;
                    }
                  }


    Uint8 *oldbrainptr = (Uint8 *) Brains[source_x][source_y];
    Uint8 *newbrainptr = (Uint8 *) Brains[dest_x][dest_y];
    for (c = 0; c < (num_of_neurons+1)*num_of_synapses; c++) {
//      newbrainptr[c] = defaultbrain[c]; // reboot childs brain (have to add defaultbrain as an argument to the breed func)
// WINDOWS V REENABLE
        newbrainptr[c] = oldbrainptr[c]; // copy living brain (experimental)
                                         // this is associated with copying
                                         // the DNA_IP of the parent instead
                                         // of resetting it, above, too...
                                         // i dunno but it will let them
                                         // run the whole dna of any size
                                         // i choose at least... through
                                         // strain tiime
    }
    neuroncount[dest_x][dest_y] = neuroncount[source_x][source_y];
    offspring[source_x][source_y][0] = 0;
//    offspring[source_x][source_y][1] = 255;
    offspring[dest_x][dest_y][0] = 0;
//    offspring[dest_x][dest_y][1] = 255;
    return recurse;
}

void showprog(Uint8 *prog, char *opcd, unsigned int proglen, unsigned int ip, unsigned int dp, Uint8 *data) {
  unsigned int i = 0;
  printf("\n\nProgram:\n");
  for (i = 0; i<proglen;i++){
    printf("%c ", opcd[prog[i]]);
  }

  printf("\nData:\n");

  unsigned int p = 0;  
  for (p = 0; p < 8; p++) {
    printf("%i ", data[p]);
  }
  
  printf("\n\n");
}

void loadSoundFromView (Mix_Chunk *whatsound, float table[gridcols][gridrows], float waveStep, float minval, float maxval) {
        unsigned int p;
        unsigned int j;
        unsigned int i;
        float ss1wavepos = 0;
        float ss1avg;
        float oldwp = -1;
        float divisor = maxval - minval;

        int tj=0;
        int ti=0;
        int oldtj = 0;
        int oldti = 0;

        for (p = 0; p < popsize; p++) {
          if ((unsigned int) oldwp == (unsigned int) ss1wavepos){
            if (table[tj][ti] > minval) {
              ss1avg = (((((float) (((float)table[oldtj][oldti]-(float)minval))/(float)divisor)* 255.0f) + ss1avg)/2.0f);
            } else {
              ss1avg = (ss1avg/2.0f);
            }
          Uint16 *vip=  (*whatsound).abuf;vip[(unsigned int) oldwp] = (Uint16) ss1avg*256;

//            printf("2 %i \n",             (*whatsound).abuf[(unsigned int) ss1wavepos]);
//              printf ("2 %f %i %i %i %f\n", soundRewards[tj][ti], tj, ti, ss1avg, ss1wavepos);

          } else {
            if (table[tj][ti] > minval) {
              ss1avg = (float) ( (float) table[tj][ti] - (float) minval);
              ss1avg = ((ss1avg/(float)divisor)*255.0f);
            } else {
              ss1avg = 0;
            }
  //          (*whatsound).abuf[(unsigned int) ss1wavepos] = (Uint8) ss1avg;
         Uint16 *vip=  (*whatsound).abuf;vip[(unsigned int) ss1wavepos] = (Uint16) ss1avg*256;
//              printf ("3 %f %i %i %i %f\n", soundRewards[tj][ti], tj, ti, ss1avg, ss1wavepos);


//            printf("1 %i \n",             (*whatsound).abuf[(unsigned int) ss1wavepos]);

          }

          if (ss1wavepos - oldwp >= 1) { // stretch population to fit if
                                         // undersize ... :|
            unsigned int aaa;
            for (aaa = (unsigned int)oldwp; aaa < (unsigned int)ss1wavepos; aaa++) {
      //        (*whatsound).abuf[(unsigned int) aaa] = (Uint8) ss1avg;         
               Uint16 *vip=  (*whatsound).abuf;vip[(unsigned int) aaa] = (Uint16) ss1avg*256;   
            }
              if ((ss1wavepos + waveStep >= (*whatsound).alen && ss1wavepos < (*whatsound).alen)) {
                for (aaa=(unsigned int)ss1wavepos+1;aaa<(unsigned int)(*whatsound).alen;aaa+=1) {     // to fit the sound, sheesh
          //      (*whatsound).abuf[(unsigned int) aaa] = (Uint8) ss1avg; // and fill the end
                   Uint16 *vip=  (*whatsound).abuf;vip[(unsigned int) aaa] = (Uint16) ss1avg*256;
                }  
              }  

          }


          tj++;
          oldtj = j;
          oldti = i; // christ
          if (tj >= gridcols) {
            tj = 0;
            ti += 1;
          }

          oldwp = ss1wavepos;
          ss1wavepos += waveStep;
        }
      
}

    Uint8 *uisoundtable;
    float *fsoundtable;
    int *isoundtable;
    float minsound = 0;
    float maxsound = 0;

#undef main

int main(int argc, char *argv[]) {
  int lastSoundBuf = 1;
  //int waveVotesCtr = 0; // find waveVotes[][] later

  printf("Initializing SDL.\n");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }
  printf("SDL initialized.\n");
                

    int audio_rate = 8000;
    Uint16 audio_format = AUDIO_U16SYS;
    int audio_channels = 1;
    int audio_buffers = 128;


    if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0)
    {
       fprintf(stderr, "Unable to initialize audio: %s\n", Mix_GetError());
       exit(1);
     }
     
     Mix_AllocateChannels(2);
                 
    printf("Loading target sound %s\n", targetWavFile);
    sound = Mix_LoadWAV(targetWavFile);
    if(sound == NULL) {
      fprintf(stderr, "Unable to load WAV file: %s\n", Mix_GetError());
    }

    printf("Setting up sound completion callback\n");


    printf("Playing target sound. Ohboy\n");
    int channel;
    channel = Mix_PlayChannel(-1, sound, 0);
    if(channel == -1) {
      fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
    }
        
//    printf("Wait\n");        
//    for(p=0;p<2000000000;p++){}

    int p = 0;

    printf("sound.alen = %i\n", (*sound).alen);
    printf("sound.volume = %i\n", (*sound).volume);
    (*sound).volume = 128;
    for (p=0; p < 20; p++) {
      printf("sound.abuf[%i] = %i\n", p, (*sound).abuf[p]);
    }

    // ok so then we can go

    printf("Loading dummy.wav\n");
    soundBuffer = Mix_LoadWAV("/tmp/dummy.wav"); // is 4000 samples
    soundBuffer2 = Mix_LoadWAV("/tmp/dummy.wav"); // is 4000 samples
//    printf("Loading null.wav\n");
//    soundBuffer3 = Mix_LoadWAV("null.wav"); // is 1 samples

    (*soundBuffer).volume = 100; // random pops are loud
    (*soundBuffer2).volume = 100;
//    (*soundBuffer3).volume = 50; // dont use this dont know why
                                // problem was 200ms samples
                                // were too short and screwed up
                                // SDL not that I needed to play it rly

    if(soundBuffer == NULL || soundBuffer2 == NULL) {
      fprintf(stderr, "Unable to load WAV file: %s\n", Mix_GetError());
    }


    printf("buffer soundBuffer.alen = %i\n", (*soundBuffer).alen);
    printf("buffer soundBuffer2.alen = %i\n", (*soundBuffer2).alen);


    //printf("sorry 15 second wait for intro sound to finish find Delay(10000)\nand increase it if even this isnt enough ok, ha\n");
    //SDL_Delay(10000);


    channel = Mix_PlayChannel(-1, soundBuffer, 0);
    if(channel == -1) {
      fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
    }
    //SDL_Delay(2000);

    channel = Mix_PlayChannel(-1, soundBuffer2, 0);
    if(channel == -1) {
      fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
    }
    //SDL_Delay(2000);

//    channel = Mix_PlayChannel(-1, soundBuffer3, 0);
//    if(channel == -1) {
//      fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
//    }
//    SDL_Delay(1000);

        
//
//    whichsound = 1;
//    printf("Wait\n");        
//    for(p=0;p<2000000000;p++){}

    printf("soundBuffer.alen = %i\n", (*soundBuffer).alen);

    for (p=0; p < 20; p++) {
      printf("soundBuffer.abuf[%i] = %i\n", p, (*soundBuffer).abuf[p]);
    }



//  FILE*rand=fopen("/dev/urandom","r");
//  srand(getc(rand));
//  srand(getc(rand));
//  fclose(rand);
// ^ was for linux
//  srand( (unsigned int)time( NULL ));
srand(time(NULL)); printf("USING RANDOM SEED 100 DISABLE THIS *** \n");
  // ^ win


  char *logfile = "ca-ga.log";
  FILE*lf=fopen(logfile,"w");

//  printf("cat /dev/urandom to stdin to start it\n");  
  
  Uint8 CA_on = 1;
  Uint8 DNA_on = 1;
  Uint8 sex_on = 1;
  Uint8 view = 99;

  Uint8 soundSource = 0; // 0 == output sound wave, 1 == sound rewards,
                         // maybe 2+ will be each other display made into
                         // sound since there is a sound rewards view, 14

//  int drawevery = 60;
//  int drawevery = 13;
  int autosaveevery = 30000; // if 50 cycles is one second this is about an
                             // an hour
  unsigned int randomdivisor = RAND_MAX>>8;

  int drawevery = 1;
  int exitafter = 0;
//  int biteAmount = 7; // i evolved for a while at these settings but
//  int freeGiveBonus = 5; // i dont think they're enough
//  int biteAmount = 12; // 
//  int freeGiveBonus = 7; // cells still don't live long at these values

//  int biteAmount = 5;
//  int freeGiveBonus = 3; 
//  int freeEnergyToOffspring = 7;

  
//  int gridrows = 170;
//  int gridcols = 213; // you get weird ropes around this ratio
                        // fuck with it, maybe smaller and they
                        // knot up and shit

//  int gridrows = 70; // ok
//  int gridcols = 110;

  // int gridrows = 52; // also ok
  // int gridrows = 66;

//  int gridrows = 104;
//  int gridcols = 142;

//  int gridrows = 111;
//  int gridcols = 142; // make it fit (ropy)
  
  int minspacingx = 2;
  int minspacingy = 2;

  unsigned int delayevery = 100000; // frames
  unsigned int delayctr = 0;


//  int minspacingx = 1;
//  int minspacingy = 1;
  // maybe store a max IP per cell and only mutate offsets up to it would be
  // smart
//  int mutantrate = 9; // 1/n offspring will be mutated. minimum is 1 (100%)
//  int remutaterate = 4; // 2/n chance of repeat mutations

//  int DNA_Length = 16384; // even numbers only ok, over 256 is ok (offset takes 2 bytes randomness)
//  int DNA_Length = 4096;

  int DNA_Length_div_two = DNA_Length / 3; // remember only even dna lengths
                                           // sorry use multiples of 3 for
                                           // neural version
  float DNA_View_Cell_Size_Divisor = 0.9f; // or use 2 most of the time
                                      // it crashed for me at 3 one time
  printf("init dna\n");
  Uint8 **DNA[gridcols][gridrows];
  Uint8 **dnaptr = &DNA;

  Uint8 **Brains[gridcols][gridrows];
  Uint8 did_fire[num_of_neurons+1];
  Uint8 CellZero_did_fire[num_of_neurons+1];
  Uint8 neuralzeroes[num_of_neurons+1];
  Uint8 neuralones[num_of_neurons+1];
//  Uint8 j = 0;
//  Uint8 i = 0;
// for larger grid, use ints to loop
  int j = 0;
  int i = 0;
  for (j = 0; j <= num_of_neurons; j++) { did_fire[j] = 0;}
  for (j = 0; j <= num_of_neurons; j++) { CellZero_did_fire[j] = 0;
                                          neuralzeroes[j] = 0; 
                                          neuralones[j] = 1; } 
  Uint8 *defaultbrain[num_of_neurons+1][num_of_synapses];
  // default brain (these synapses cant be removed)
  Uint8 neuroncount[gridcols][gridrows];
  for (i = 0; i < gridrows; i++) {
    for (j = 0; j < gridcols; j++) {
      neuroncount[j][i] = cortical_neurons;// size of defaultbrain 
    }
  }
//  int motor = 240;
//  int sensor = 8;
//  int sensorormotor = 0;

  unsigned int stimdecayctr = 0; // we'll need this later
  
  int t = 0;
  defaultbrain[0][0] = 0;
  defaultbrain[0][1] = 0;
  for (t = 2; t < num_of_synapses; t+=4) {
    defaultbrain[0][t] = 0;
    defaultbrain[0][t+1] = 0;
    defaultbrain[0][t+2] = 1;
    defaultbrain[0][t+3] = 32;
  }

  for (j = 1; j <= cortical_neurons; j++) { // starts at 1... 0 is no neuron... 65 is temp sense
    int p = 0;
    int k = 0;
    if (j == 1) { p = cortical_neurons; } else { p = j-1; }
    if (j == cortical_neurons) { k = 1; } else { k = j+1; } 
    defaultbrain[j][0] = 0; // potential
    if (j != 71) {
      defaultbrain[j][1] = 20; // threshold
    } else {
      defaultbrain[j][1] = 255; // neuron 71 for sound voting must stay
                                // 255 threshold

    }
    

    defaultbrain[j][2] = p;
    defaultbrain[j][3] = 0; // 0 = excit, 1 = inhib, 2 = excit plas, 3 = inhib plas
    defaultbrain[j][4] = 1; // weight (signal multiplier)
                            // note we take the top 5 bits of this so the
                            // first weight that really means 2 is, 32
    defaultbrain[j][5] = 32; // plasticity modifier (reduced by inhibitory
                            // firing on plastic neurons, increased by excit,
                            // subtracted by 32 and multiplied by weight if plast)
    
    defaultbrain[j][6] = k;
    defaultbrain[j][7] = 1; // inhib
    defaultbrain[j][8] = 1; // weight
    defaultbrain[j][9] = 32;

    defaultbrain[j][10] = ((rand())%(cortical_neurons))+1;
    defaultbrain[j][11] = 0; // inhib
    defaultbrain[j][12] = 1; // weight
    defaultbrain[j][13] = 32;

    defaultbrain[j][14] = ((rand())%(cortical_neurons))+1;
    defaultbrain[j][15] = 1; // inhib
    defaultbrain[j][16] = 1; // weight
    defaultbrain[j][17] = 32;

    printf("wire cortical neuron %i to %i and %i\n", j, p, k);

/*    if (sensorormotor == 0) {
      defaultbrain[j][10] = sensor;
      sensor += 1;
      if (sensor > 32) { sensor = 1; }
      sensorormotor = 1;
    } else {
      defaultbrain[j][10] = motor; // no neurons with motors and sensors
      motor += 1;
      if (motor > 255) { motor = 224; }
      sensorormotor = 0;
    }

/*    defaultbrain[j][11] = 0; // inhib
    defaultbrain[j][12] = 1; // weight
    defaultbrain[j][13] = 0; */
    // look... instead of using synapses for motor and sensor connections,
    // since i don't want them adding and removing those anyway just synapses
    // to and from neurons that are permanently wired to a motor or sensor,
    // just read them staggered from 0 to 62 as if those 32 neurons were
    // hooked up to the respective sensor, and from 1 to 63 as if they had
    // the respective motor... see in the brains run... this will be easy
    // and then i can have 256 neurons again

    int t = 18;
    for (t = 18; t < num_of_synapses; t+=4) {
      defaultbrain[j][t] = 0;
      defaultbrain[j][t+1] = 0;
      defaultbrain[j][t+2] = 1;
      defaultbrain[j][t+3] = 32;
    }
  }

  for (j = 72; j <= num_of_neurons; j++) {
    defaultbrain[j][0] = 0;
    defaultbrain[j][1] = 10;
    int t = 2;
    for (t = 2; t < num_of_synapses; t+=4) {
      defaultbrain[j][t] = 0;
      defaultbrain[j][t+1] = 0;
      defaultbrain[j][t+2] = 1;
      defaultbrain[j][t+3] = 32;
    }
  }

  unsigned int DNA_IP[gridcols][gridrows];
  // maybe I can give them n heads a piece and when bumped, they can jmp
  // the head which some index i just increment to dnalength per frame is
  // closest to... rather than every head or something. then they can
  // have some parallel evaluation. just add [heads] here and a heads
  // loop to the dna run. later on
  // oh give them a head for each direction then pokes can jump the head
  // for the dir they came from, 8 heads
  unsigned int DNA_DP[gridcols][gridrows];
  unsigned int generations[gridcols][gridrows];
  Uint8 skips[gridcols][gridrows];
  Uint8 newskips[gridcols][gridrows];
  Uint8 neurskipsandstuns[gridcols][gridrows];

  // DNA:
  // 1 byte, 1 byte
  // byte 1: suck/give/wait
  // byte 2: direction
  // if sucking puts a cell under 0 copy dna to it
  // with mutations
#define drawsbetweenscoreoutput 1000
#define dumplogevery 3000
int dumplogctr = 0;
#define newprogevery 1024
  int newprogctr= newprogevery ;
  int c = 0;

  j = 0;
  int lostfights = 0;
  int wonfights = 0;
  int nops = 0;
  int neuralnops = 0;
  int neuralskips = 0;
  int neuralstuns = 0;
  // not too sure... maybe a fight should be harder with a cell who is NOP'ing
  // ok. it is
  printf ("load dna\n");
  for (i = 0; i < gridrows; i++) { // what if it was self-modifying? three new
    for (j = 0; j < gridcols; j++) { // opcodes could move a head and pop
      DNA_IP[j][i] = 0;                // the cell's value or one from a stack.
                                         // hm
      DNA_DP[j][i] = 0; // self modification will be so trippy with sound
      skips[j][i] = 0;
      newskips[j][i] = 0;
      generations[j][i] = 0;
      printf ("Malloc DNA %i,%i\n",j,i);
      DNA[j][i] = malloc(DNA_Length*2);
      printf ("Malloc Brain %i,%i\n",j,i);
      Brains[j][i] = malloc((num_of_neurons+1)*(num_of_synapses)+1); // potential
                                                               // threshold
                                                               // then synapses
      int t = 0;
      int neur = 0;
	printf ("fill brain\n");
      Uint8 *brainptr = Brains[j][i]; 
	printf("pointer ok\n");
      for (t = 0; t <= num_of_neurons; t++) {
        for (c = 0; c < num_of_synapses; c++) {
          *brainptr = (Uint8) defaultbrain[t][c];
          brainptr++;
        }
      }
                                                         
//      Uint8 *tempdna = malloc(DNA_Length); // wtf
	printf("fill dna\n");
      Uint8 *thisdna = DNA[j][i]; // these should be bit packed (its only 6 bits information per opcode & operand atm)
	printf("pointer ok\n");
      for (c = 0; c <= DNA_Length; c++) {
        thisdna[c] = (rand())%6;
        c++;
        thisdna[c] = (rand())%(num_of_neurons+1);
        c++;
        thisdna[c] = (rand())%(num_of_neurons+1);
        c++;
        thisdna[c] = (rand())%(num_of_neurons+1);
      }
    }
  }
  printf ("random dna ready... default brains built\n");
  Uint8 *thisdna = &DNA;
  printf ("%i\n", (Sint16) thisdna[0]);
  printf ("%i\n", (Sint16) (rand()/RAND_MAX));
  
  int cellwidth = (screenwidth/gridcols)-minspacingx;
//  int cellheight = (screenheight/(gridrows+((DNA_Length/DNA_View_Cell_Size_Divisor)/(gridcols*DNA_View_Cell_Size_Divisor))+1))-minspacingy;

  int cellheight = ((screenheight/((gridrows)+((num_of_neurons/DNA_View_Cell_Size_Divisor)/(gridcols*DNA_View_Cell_Size_Divisor))-1))-minspacingy);

  int xspace = minspacingx+((screenwidth-(gridcols*(cellwidth+minspacingx))) / gridcols);
//  int yspace = minspacingy+((screenheight-((gridrows+((DNA_Length/DNA_View_Cell_Size_Divisor)/(gridcols*DNA_View_Cell_Size_Divisor))+1)*(cellheight+minspacingy))) / (gridrows+(DNA_Length/gridcols)+1));
  int yspace = minspacingy+((screenheight-((gridrows+((num_of_neurons/DNA_View_Cell_Size_Divisor)/(gridcols*DNA_View_Cell_Size_Divisor))-1)*(cellheight+minspacingy))) / (gridrows+(num_of_neurons/gridcols)+1));
  // ^^ 254 == num_of_neurons (done)

  printf ("screenwidth %i\nscreenheight %i\ngridX %i\ngridY %i\ncellwidth %i\ncellheight %i\nxspace %i\nyspace %i\n", 
           screenwidth,    screenheight,    gridcols, gridrows, cellwidth,    cellheight,    xspace,    yspace);

  Uint8 grid[gridcols][gridrows];

//  int tctr=0;
  printf ("get grid\n");
  for (i = 0; i < gridrows; i++) {
    for (j = 0; j < gridcols; j++) {
//      grid[j][i] = (j*i)*4; // interesting seed
      grid[j][i] = (rand()/randomdivisor);
//      grid[j][i] = tctr; tctr++; if(tctr>255){tctr=0;}
//      printf ("grid[%i][%i] = %i\n", j, i, grid[j][i]);
      if (grid[j][i] > 255) { grid[j][i] = 0; }
//      grid[j][i] = 30;
    }
  }

  printf("Initializing SDL.\n");
    
  /* Initialize defaults, Video and Audio */
//  if((SDL_Init(SDL_INIT_VIDEO)<0)) {
//    printf("Could not initialize SDL: %s.\n", SDL_GetError());
//    exit(-1);
//  }

  printf("SDL initialized.\n");
  
  /* Clean up on exit */
  atexit(SDL_Quit);

  SDL_Event event;
  
printf("video\n");          
    /*
     * Initialize the display in a 640x480 8-bit palettized mode,
     * requesting a software surface                             
     */
    SDL_Surface *screen;
    screen = SDL_SetVideoMode(screenwidth, screenheight, 8, SDL_SWSURFACE);
    if ( screen == NULL ) {
        fprintf(stderr, "Couldn't set %ix%ix8 video mode: %s\n",
                        screenwidth, screenheight, SDL_GetError());
        exit(1);
    }

printf("video up\n");

        /* Create a display surface with a grayscale palette */
        //SDL_Surface *screen;
        SDL_Color colors[257];
        //int i;

        /* Fill colors with color information */

        for(i=0;i<64;i++){
	colors[i].r=0;
	colors[i].g=0;
	colors[i].b=i*4;
}

        for(i=0;i<64;i++){
	colors[i+64].r=i*4;
	colors[i+64].g=0;
	colors[i+64].b=252-i*4;
}

        for(i=0;i<64;i++){
	colors[i+128].r=252;
	colors[i+128].g=i*4;
	colors[i+128].b=0;
}

        for(i=0;i<64;i++){
	colors[i+192].r=252;
	colors[i+192].g=252;
	colors[i+192].b=i*4;
}


// greyscale palette:
/*        for(i=0;i<256;i++){
          colors[i].r=i;
          colors[i].g=i;
          colors[i].b=i;
        }


colors[253].r = 64;
colors[253].g = 0;
colors[253].b = 0;

colors[254].r = 128;
colors[254].g = 0;
colors[254].b = 0;

colors[255].r = 255;
colors[255].g = 0;
colors[255].b = 0; */

        /* Set palette */
       SDL_SetPalette(screen, SDL_LOGPAL|SDL_PHYSPAL, colors, 0, 256);

Sint8 CA_RULES[9][9][9];

        for(i=0;i<9;i++){
        for(j=0;j<9;j++){
        for(c=0;c<9;c++){
                        CA_RULES[i][j][c]=0;//((Sint16)(rand()%16))-8;
			//CA_RULES[i][j][c]=(i*4)+(j*2)+(c)-150;

		}
		}
		}


printf("CA_RULES loaded\n");

  Uint8 tgrid[gridcols][gridrows];
  for (i = 0; i < gridrows; i++) {
    for (j = 0; j < gridcols; j++) {
      tgrid[j][i] = grid[j][i];
    }
  }

  Uint8 dnarun[gridcols][gridrows];
  for (i = 0; i < gridrows; i++) {
    for (j = 0; j < gridcols; j++) {
      dnarun[j][i] = grid[j][i];
    }
  }

  Uint8 dnarun_sub[gridcols][gridrows];
  for (i = 0; i < gridrows; i++) {
    for (j = 0; j < gridcols; j++) {
      dnarun[j][i] = grid[j][i];
    }
  }

  Uint8 dnarun_add[gridcols][gridrows];
  for (i = 0; i < gridrows; i++) {
    for (j = 0; j < gridcols; j++) {
      dnarun[j][i] = grid[j][i];
    }
  }

  Uint8 actions_view[gridcols][gridrows];
  Uint8 actions_view2[gridcols][gridrows];  
  Uint8 actions_view3[gridcols][gridrows];
  Uint8 actions_view4[gridcols][gridrows];
  Uint8 actions_view5[gridcols][gridrows];
  for (i = 0; i < gridrows; i++) {
    for (j = 0; j < gridcols; j++) {
      dnarun[j][i] = grid[j][i];
    }
  }

Sint16 newpots[num_of_neurons+1];
for (i = 0; i <= num_of_neurons; i++) { newpots[i] = 0; }

  Uint8 offspring[gridcols][gridrows][17]; // to buffer reproduction for second run
                                        // NOTE if you need a grid larger than
                                        // 254x254, change Uint8 here to an int !
                                        // and initialize offspring[] initial
                                        // values to -1 instead of 255 and
                                        // change the check in the breed run
                                        // accordingly and the set in the
                                        // dna run
  for (i = 0; i < gridrows; i++) {
    for (j = 0; j < gridcols; j++) {
      offspring[j][i][0] = 0;
//      offspring[j][i][1] = 255;
    }
  }  

//  int lastip[gridcols][gridrows]; // for better mutations
//  for (i = 0; i < gridrows; i++) {
//    for (j = 0; j < gridcols; j++) {
//     lastip[j][i]=1;
//    }
//  } // oh it only takes one int
  int maxIP = 0;

// probably need a table for graphing actions

// what about buffering the actions of low energy critters for n frames
// and letting high energy critters act faster?
  int giveamount = biteAmount+freeGiveBonus; // careful

  Uint8 *waveVotes[4001]; // wow. ok so if you ever had a population big
                              // enough to vote for each sound sample two or
                              // four times or something, and they were
                              // somehow getting like a hundred neural frames
                              // per half-second, like if the sim was 50 fps
                              // let's say and you had 8192 cells, a few of
                              // the samples will be covered by 3 cells and
                              // with 2 neural sub-runs, that'd add up to
                              // 300 total votes, if they voted for the
                              // same byte it'd roll over to 45. That's real
                              // bad but it's a corner case since this is so
                              // slow and hard to resize, uh, just put a check
                              // to see if the stored vote is 255 already
                              // everywhere one is incremented or, make this
                              // table ints instead, hopefully that works
  float soundRewards[gridcols][gridrows];
  Uint8 selfmod[gridcols][gridrows];

  for (p = 0; p < 4001; p++) {
  	waveVotes[p]=malloc(256);
     int P = 0;
     for (P = 0; P < 256; P++) {
       waveVotes[p][P] = 0;
      }
  }

  Uint8 stims[gridcols][gridrows];  // haha not stimuli, stimulants
                                    // this is gonna be two directionally
                                    // unfair because we sweep the board
                                    // both ways in case of things like
                                    // this. that's way faster

  Uint8 avgOrSnapshot = 0;
  float soundVals[gridcols][gridrows]; // this is a temporary storage for
                                       // averages or snapshots of views used
                                       // as sound channels

  Uint8 firstsoundavg = 0;


  Uint8 tstimuli[gridcols][gridrows][4][8];  // ok
  Uint8 stimuli[gridcols][gridrows][4][8];
  for (i=0;i<gridrows;i++) {
    for (j=0;j<gridcols;j++) {
      stims[j][i] = 0;
      for (t=0;t<4;t++) {
        for (c=0;c<8;c++) {
          tstimuli[j][i][t][c] = 1; // why do i set these high
          stimuli[j][i][t][c] = 1; 
          soundRewards[j][i] = 0; // zero this too. first time
          selfmod[j][i] = 0;
        }
      }
    }
  }
  
  Uint8 actions[4][8];
  for (i=0;i<4;i++) {
    for (j=0;j<8;j++) {
      actions[i][j] = 0;
    }
  }

  Uint8 sexctr[gridcols][gridrows];
  for (i = 0; i < gridrows; i++) {
    for (j = 0; j < gridcols; j++) {
      sexctr[j][i] = 0;
    }
  }

  Uint8 inputs[gridcols][gridrows];
  for (i = 0; i < gridrows; i++) {
    for (j = 0; j < gridcols; j++) {
      inputs[j][i] = 0;
    }
  } 


  Uint8 outputs[gridcols][gridrows];
  for (i = 0; i < gridrows; i++) {
    for (j = 0; j < gridcols; j++) {
      outputs[j][i] = 0;
    }
  } 


  t = 0;
  int tt = 0; // no
  float avggen = 0;
  float oldavggen = 0;
  float avgSoundReward = 0;
  Uint32 turnsTaken = 0;
  //float oldavgSoundReward = 0;
  //  int y = 0;
  int gridlastx = gridcols-1;
  int gridlasty = gridrows-1;
  int up;
  int down;
  int left;
  int right;
  unsigned int maxrecursions = 0;
  unsigned int cycles=0;
  unsigned int progsgot = 0; // for brainfuck fitness func
  unsigned int sdf = 0;
  unsigned int outputpenalty = 2; // for non salient outputs
  unsigned int inputscost = 1;
  unsigned int goods = 0;
  unsigned int good_output_reward = 5; // for good outputs
  
  unsigned int outputsctr = 0;
  unsigned int dataloop = 0;
  unsigned int inputcost = 1;
  int highgen = 0;
  int lowgen = -1;
  int lowgeninpop = -1;
  int highestgen = 0;
  int skipsctr = 0;
  int pokes = 0;
  int gives = 0;
  int bites = 0;
  int kills = 0;
  int breeds = 0;
  int splits = 0;
  int autosavectr = 0;
  int viewdata1;
  int viewdata2;
  int *viewdata3;
  Uint8 *viewdata4;

  int showsynapses = 1;

  unsigned int datalen = 8;
  Uint8 data[datalen];
  unsigned int proglen = 32;
  Uint8 prog[proglen];

  for (t = 0; t < 120; t++) { drawgrid(screen, Brains, neuroncount[0][0], CellZero_did_fire, *grid, gridrows, gridcols, cellwidth, cellheight, xspace, yspace, screenwidth, screenheight, DNA_View_Cell_Size_Divisor, DNA_Length, 0, 0, 0, 0, 0, 0, 0, 1, 1); 
    SDL_UpdateRect(screen, 0, 0, screenwidth-1, screenheight-1);
  } //printf("intro draw\n"); }
  black(screen);

  t = 0;

  printf("\n\nHit 'h' in the window for help.\n'v' changes views.\n'j' changes sound sources.\nhearing evolved sound atm. it will be like loud static at first.\nother views may sound more like the target wav.\nwhen the grid is evolved some views will sound less like it and others more\nthis represents evolutionary progress.\n\n");

  int reverseEvaluation = 0;
  signed int inc;
  int startx;
  int starty;
  int lastx;
  int lasty;

  float waveStep = 4000.0f / (float) ((float) gridcols* (float)gridrows);
  float negWaveStep = 0-waveStep;
  float curWaveStep = 0;
  float targetWavePos = 0;

  Uint8 z = (Uint8) gridcols>>1; Uint8 y = gridrows>>1;
  Uint8 z2 = (Uint8) gridcols>>2; Uint8 y2 = gridrows>>2;
  Uint8 z3 = (Uint8) gridcols>>4; Uint8 y3 = gridrows>>4;  
  Uint8 gridrowsminusy2 = gridrows - y2;
  Uint8 gridcolsminusz2 = gridcols - z2;
  // ^ move these inside the loop if you allow resizing the grid

  unsigned int soundoffs = 0; // hmm

  while(1) {

    // live
    Uint8 run; int i; int j; 

    float wavePos = 0;
     float oldwavepos = 0;
  
 //     float *svptr = soundVals;
  
//    printf("sniff out win crash 1\n");
  
       Uint8 lastview = 17; // just change this if you add a view. then it will
                            // appear in multi-view. you also have to change
                            // drawgrid saying whether that view is a uint8 or
                            // int table
 
   Uint8 changedSound = 0;
  /* Poll for events. SDL_PollEvent() returns 0 when there are no  */
  /* more events on the event queue, our while loop will exit when */
  /* that occurs.                                                  */
  while( SDL_PollEvent( &event ) ){
    /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
    switch( event.type ){
      case SDL_KEYDOWN:
                /* Check the SDLKey values and move change the coords */
                switch( event.key.keysym.sym ){
                    case SDLK_RETURN: // this is nice
                      if (soundSource > 0) { view = soundSource - 1; 
                      printf("View %i selected ("); sayview(view); black(screen);}
                      if (soundSource == 0) { view = 99; 
                      printf("View %i selected ("); sayview(view); black(screen);}
                      break;
                    case SDLK_b:
                           for(i=0;i<9;i++){
        for(j=0;j<9;j++){
        for(c=0;c<9;c++){
                        CA_RULES[i][j][c]=20;//((Sint16)(rand()%16))-8;
			//CA_RULES[i][j][c]=(i*4)+(j*2)+(c)-150;

		}
		}
		}
break;
                    case SDLK_m:
                      printf("Multiview\n");
                      black(screen);
                      view = 99;
                      break;
                    case SDLK_COMMA:
                    if ((*soundBuffer).volume > 4) {
                      (*soundBuffer).volume -= 5;
                      (*soundBuffer2).volume -= 5;
                    } else {
                      (*soundBuffer).volume = 0;
                      (*soundBuffer2).volume = 0;
                    }
                    printf("sound buffer volume = %i\n", (*soundBuffer).volume);
                    break;
                    case SDLK_PERIOD:
                    if ((*soundBuffer).volume < 250) {
                      (*soundBuffer).volume += 5;
                      (*soundBuffer2).volume += 5;
                    } else {
                      (*soundBuffer).volume = 255;
                      (*soundBuffer2).volume = 255;
                    }
                    printf("sound buffer volume = %i\n", (*soundBuffer).volume);
                    break;
                    case SDLK_g:
                      if (view == 99 || (soundSource > 0 && soundSource == view+1)) { soundSource = 0; } else if (view != 99) { soundSource = view+1; }
                      changedSound = 1;
                      break;
                    case SDLK_SLASH:
                        printf("");
                    case SDLK_h:
                        printf ("(( Key help\n\
(V) to toggle views\n\
(M) to go back to multi-view\n\
(D) to toggle DNA\n\
(C) to toggle CA\n\
(S) to toggle sex\n\
(X) to export a DNA\n\
(L) to load some DNA\n\
(Y) to toggle synapse view\n\
(J) to toggle sound source ahead (look at multi-view for a selection box)\n\
(K) to toggle sound source backward\n\
(A) to switch between snapshots and averages of views made into sound\n\n\
(,) << volume down\n\
(.) << volume up\n\n\
PgDwn saves the whole population to files starting ca-ga.whole-pop.*\n\
PgUp loads the whole population from files starting ca-ga.whole-pop.*\n\n\
(Q) to export some strains & quit\n");                        
                    break;
                    case SDLK_d:
                        if (DNA_on) {DNA_on=0;printf("DNA run suspended! D to resume\n"); } else {DNA_on=1;printf("DNA run enabled. Thank you\n");}
                        break;
                    case SDLK_c:
                        if (CA_on) {CA_on=0;printf("CA run suspended! C to resume\n"); } else {CA_on=1;printf("CA run enabled. Good luck\n");}
                        break;
                    case SDLK_s:
                        if (sex_on) {sex_on=0;printf("Sex disallowed, S to resume\n"); } else {sex_on=1;printf("The reproductive suppression field has been disabled\n");}
                        break;
                    case SDLK_k:
                        if (soundSource < lastview+1) {
                          soundSource++;
                        } else {
                          soundSource = 0;
                        }
                        changedSound = 1;
                        break;
                    case SDLK_a:
                        if (avgOrSnapshot == 1) {
                          avgOrSnapshot = 0;
                          printf("Now taking *snapshots* for abnormal sound channels (use J/K to choose)\n");
                          firstsoundavg = 0;
                        } else {
                          avgOrSnapshot = 1;
                          printf("Now taking *averages* for abnormal sound channels (use J/K to choose)\n");
                          firstsoundavg = 1;

                          for (j = 0; j < gridcols; j++) {
                          for (i = 0; i < gridrows; i++) {
                            soundVals[j][i] = 0;
                            }
                            }

                        }
                        break;
                    case SDLK_j:
                        if (soundSource > 0) {
                          soundSource--;
                        } else {
                          soundSource = lastview+1;
                        }
                        changedSound = 1;
                        break;
                    case SDLK_v:
                        if (view == 0) {view=1;printf("Generation count view on, V to switch\n");}
                        else if (view == 1) {view=2;printf("Stun view on, V to switch\n");}
                        else if (view == 2) {view=3;printf("Breed mood view on, V to switch\n");}
                        else if (view == 3) {view=4;printf("DNA IP view on, V to switch\n");}
                        else if (view == 4) {view=5;printf("Give view on, V to switch\n");}
                        else if (view == 5) {view=6;printf("Bite view on, V to switch\n");}
                        else if (view == 6) {view=7;printf("Poke view on, V to switch\n");}
                        else if (view == 7) {view=8;printf("Fight view on, V to switch\n");}
                        else if (view == 8) {view=9;printf("NOP view on, V to switch\n");}
                        else if (view == 9) {view=10;printf("Neuron count view on, V to switch\n");}
                        else if (view == 10) {view=11;printf("Brainfuck Input view on, V to switch\n");}
                        else if (view == 11) {view=12;printf("Brainfuck Output view on, V to switch\n");}
                        else if (view == 12) {view=13;printf("Neural SKip/Stun of DNA view on (skips dark, stuns bright), V to switch\n");}
                        else if (view == 13) {view=14;printf("Sound reward view on, V to switch\n");}
                        else if (view == 14) {view=15;printf("Stimulant view on, V to switch\n");}
                        else if (view == 15) {view=16;printf("Self-modification view, V to switch\n");}
                        else if (view == 16) {view=17;printf("DNA DP on, V to switch\n");}
                        else if (view == 17) {view=99;
                          black(screen);
                          printf("Multi-view on, V to switch\n");
                        }
                        else if (view == 99) {black(screen);view=0;printf("Normal view (energy) on, V to switch\n");}                        

                        break;
                    case SDLK_x:
                        savecrit(highgen, DNA_Length, popsize, DNA, Brains, neuroncount, &DNA_IP, &DNA_DP, &generations, "ca-ga.best.dna", "ca-ga.best.brain");
                        savecrit(avggen, DNA_Length, popsize, DNA, Brains, neuroncount, &DNA_IP, &DNA_DP, &generations, "ca-ga.average.dna", "ca-ga.average.brain");
                        savecrit(lowgen+1, DNA_Length, popsize, DNA, Brains, neuroncount, &DNA_IP, &DNA_DP, &generations, "ca-ga.low.dna", "ca-ga.low.brain");
                        break;
                    case SDLK_q:
                        savecrit(highgen, DNA_Length, popsize, DNA, Brains, neuroncount, &DNA_IP, &DNA_DP, &generations, "ca-ga.best.dna", "ca-ga.best.brain");
                        savecrit(avggen, DNA_Length, popsize, DNA, Brains, neuroncount, &DNA_IP, &DNA_DP, &generations, "ca-ga.average.dna", "ca-ga.average.brain");
                        savecrit(lowgen+1, DNA_Length, popsize, DNA, Brains, neuroncount, &DNA_IP, &DNA_DP, &generations, "ca-ga.low.dna", "ca-ga.low.brain");
                        printf("Free DNA\n");
                        for (i = 0; i < gridrows; i++) {
                          for (j = 0; j < gridcols; j++) {
                            Uint8 *temp = DNA[gridcols][gridrows];
//                            free(&temp);
                          }
                        }
                        printf("Shutdown\n");

                        //SDL_Delay(1000);

      printf ("SDL_CloseAudio();\n");
        SDL_CloseAudio();

/*    printf("play null.wav\n");
    channel = Mix_PlayChannel(-1, soundBuffer3, 0);

    SDL_Delay(100);
    printf("play null.wav\n");

    channel = Mix_PlayChannel(-1, soundBuffer3, 0);

    SDL_Delay(100);

      printf ("SDL_CloseAudio();\n");
        SDL_CloseAudio(); */
        
printf ("Return 0\n");
                        return 0;
                        break;
                    case SDLK_l:
                        printf("Load ca-ga.load.dna\n");
                        loadcrit(DNA_Length, popsize, DNA, Brains, neuroncount, &DNA_IP, &DNA_DP, &generations, "ca-ga.load.dna", "ca-ga.load.brain");
                        for (j=0;j<gridcols;j++){
                          for (i=0;i<gridrows;i++) {
                            stims[j][i] = 0;
                          }
                        }
                        break;
                    case SDLK_y:
                        printf("Synapse display toggled ");
                        if (showsynapses == 0) {
                          printf("(fired)\n");
                          showsynapses = 1;
                        } else if (showsynapses == 1) { 
                          printf("(half)\n");
                          showsynapses = 2;
                        } else if (showsynapses > 1 && showsynapses < 4) {
                          printf ("(all)\n");
                          showsynapses = 5;
                        } else if (showsynapses == 5) {
                          printf ("(off)\n");
                          showsynapses = 0;
                        }
                        break;

                    case SDLK_r:
                        printf("Load ca-ga.whole-pop.load.dna (make sure its exists)\n");
				printf("Load ca-ga.whole-pop.load.brain (make sure its exists)\n");
                        loadall(DNA_Length, popsize, DNA, Brains, neuroncount, &DNA_IP, &DNA_DP, &generations, "ca-ga.whole-pop.load.dna", "ca-ga.whole-pop.load.brain");
                        for (j=0;j<gridcols;j++){
                          for (i=0;i<gridrows;i++) {
                            stims[j][i] = 0;
                          }
                        }
                        break;
                    case SDLK_f:
                        saveall(DNA_Length, popsize, DNA, Brains, neuroncount, &DNA_IP, &DNA_DP, &generations, "ca-ga.whole-pop.dna", "ca-ga.whole-pop.brain");
                        break;
                    default:
                        break;
                }
        break;

      case SDL_KEYUP:
        break;

      default:
        break;
    }
  }




    if (changedSound) {
      if (soundSource == 0) {printf("Output sound wave playback (soundSource 0), J to switch\n");\

          if (soundSource > 0 && avgOrSnapshot == 1) {
            for (j = 0; j < gridcols; j++) {
              for (i = 0; i < gridrows; i++) {
                soundVals[j][i] = 0;  // avoid bad noise when averaging
                                      // and change displays
              }
            }
            firstsoundavg = 1;
          }

      isoundtable=0;\
      uisoundtable=0;\
      fsoundtable=0;\
      minsound = 0; maxsound = 255;
      unsigned int P;
      for (p = 0; p < 4000; p++) {
        for (P = 0; P < 256; P++) { // do this only if playing votes
          waveVotes[p][P] = 0;      // boring
        }
      } 
      }
      else if (soundSource == 1) {printf("Energy view wave playback (soundSource 1), J to switch\n"); isoundtable=0;uisoundtable=grid;fsoundtable=0; minsound = 0; maxsound = 255;printf("Low value %f, high value %f\n", minsound, maxsound);}
      else if (soundSource == 2) {printf("Generation count view wave playback (soundSource 1), J to switch\n"); isoundtable=generations;uisoundtable=0;fsoundtable=0; minsound = lowgen; maxsound = highgen;printf("Low value %f, high value %f\n", minsound, maxsound);}
      else if (soundSource == 3) {printf("Stun view wave playback (soundSource 2), J to switch\n"); isoundtable=0;uisoundtable=skips;fsoundtable=0; minsound = 0; maxsound = 255;printf("Low value %f, high value %f\n", minsound, maxsound);}
      else if (soundSource == 4) {printf("Breed mood wave playback (soundSource 3), J to switch\n"); isoundtable=0;uisoundtable=sexctr;fsoundtable=0; minsound = 0; maxsound = sexoperandpersistance*8;printf("Low value %f, high value %f\n", minsound, maxsound);}
      else if (soundSource == 5) {printf("DNA IP wave playback (soundSource 4), J to switch\n"); isoundtable=DNA_IP;uisoundtable=0;fsoundtable=0; minsound = 0; maxsound = DNA_Length;printf("Low value %f, high value %f\n", minsound, maxsound);}
      else if (soundSource == 6) {printf("Gives wave playback (soundSource 5), J to switch\n"); isoundtable=0;uisoundtable=actions_view;fsoundtable=0; minsound = 0; maxsound = 8;printf("Low value %f, high value %f\n", minsound, maxsound);}
      else if (soundSource == 7) {printf("Bites wave playback (soundSource 6), J to switch\n"); isoundtable=0;uisoundtable=actions_view2;fsoundtable=0;  minsound = 0; maxsound = 8;printf("Low value %f, high value %f\n", minsound, maxsound);}
      else if (soundSource == 8) {printf("Pokes wave playback (soundSource 7), J to switch\n"); isoundtable=0;uisoundtable=actions_view3;fsoundtable=0;  minsound = 0; maxsound = 8;printf("Low value %f, high value %f\n", minsound, maxsound);}
      else if (soundSource == 9) {printf("Fights wave playback (soundSource 8), J to switch\n"); isoundtable=0;uisoundtable=actions_view4;fsoundtable=0;  minsound = 0; maxsound = 27;printf("Low value %f, high value %f\n", minsound, maxsound);}
      else if (soundSource == 10) {printf("NOPs wave playback (soundSource 9), J to switch\n"); isoundtable=0;uisoundtable=actions_view5;fsoundtable=0;  minsound = 0; maxsound = opcodesPerFrame+3;printf("Low value %f, high value %f\n", minsound, maxsound);} // this will be +3*neuralsubruns when they can neuralnop on each one
      else if (soundSource == 11) {printf("Neuron count wave playback (soundSource 10), J to switch\n"); isoundtable=0;uisoundtable=neuroncount;fsoundtable=0;  minsound = cortical_neurons; maxsound = num_of_neurons;printf("Low value %f, high value %f\n", minsound, maxsound);}
      else if (soundSource == 12) {printf("Brainfuck Input wave playback (soundSource 11), J to switch\n"); isoundtable=0;uisoundtable=inputs;fsoundtable=0;  minsound = 0; maxsound = 255;printf("Low value %f, high value %f\n", minsound, maxsound);}
      else if (soundSource == 13) {printf("Brainfuck Output playback (soundSource 12), J to switch\n"); isoundtable=0;uisoundtable=outputs;fsoundtable=0;  minsound = 0; maxsound = 255;printf("Low value %f, high value %f\n", minsound, maxsound);}
      else if (soundSource == 14) {printf("Neural skip/stun of DNA wave playback (soundSource 13), J to switch\n"); isoundtable=0;uisoundtable=neurskipsandstuns;fsoundtable=0;  minsound = 0; maxsound = 4*neuralsubruns;printf("Low value %f, high value %f\n", minsound, maxsound);}
      else if (soundSource == 15) {printf("Sound reward wave playback (soundSource 14), J to switch\n"); isoundtable=0;uisoundtable=0;fsoundtable=soundRewards; minsound = 0; maxsound = 255;printf("Low value %f, high value %f\n", minsound, maxsound);}
      else if (soundSource == 16) {printf("Stimulant wave playback (soundSource 15), J to switch\n"); isoundtable=0;uisoundtable=stims;fsoundtable=0; minsound = 0; maxsound = 255;printf("Low value %f, high value %f\n", minsound, maxsound);}
      else if (soundSource == 17) {printf("Self-modification wave playback (soundSource 16), J to switch\n"); isoundtable=0;uisoundtable=selfmod;fsoundtable=0; minsound = 0; maxsound = 15;printf("Low value %f, high value %f\n", minsound, maxsound);}
      else if (soundSource == 18) {printf("DNA DP wave playback (soundSource 17), J to switch\n"); isoundtable=DNA_DP;uisoundtable=0;fsoundtable=0; minsound = 0; maxsound = DNA_Length;printf("Low value %f, high value %f\n", minsound, maxsound);}
    }




  
    if (reverseEvaluation > 0) {
      wavePos = waveStep*(float)((float)popsize+jitter_modifier);
      curWaveStep = negWaveStep;
      startx = gridlastx; lastx = -1; inc = -1;
      starty = gridlasty; lasty = -1;
//      startx = gridlastx; lastx = 255; inc = -1; // set 255 to allow underflow
                                                 // on Uint8 loop counters
                                                 // its just faster
//      starty = gridlasty; lasty = 255;
      reverseEvaluation = 0;
    } else {
      wavePos = 0;
      curWaveStep = waveStep;
      startx = 0; lastx = gridlastx+1; inc = 1;
      starty = 0; lasty = gridlasty+1;
      reverseEvaluation = 1;
    }   // i think the GA is so fair we don't need to do this anymore...
        // oh the recursive fair breeder will prioritize first comers on
        // the board eval order so we might as well still go both ways...
        // darn

    newprogctr += 1;

//    printf("sniff out win crash 2\n");

    if (newprogctr >= newprogevery) {
  for (j = 0; j < datalen;j++) {
    data[j] = 0;
  }

  newprogctr = 0;
//  unsigned int opcodes = 11;
//  char opcd[] = " v^<>-+,.[]";
  unsigned int opcodes = 7;
  char opcd[] = " <>-+[]";

/*  unsigned int p = 0;
  for (p = 0; p < wX*3; p++) {
    tape[p]=0;
  } */ // no tape... i'll remove . and , and let them guess bytes from the
       // data field instead

  printf("bf-ga.c.\n");
  printf("%i opcodes: ' ' NOP < ++DP < --DP\n+ ++*DP - --*DP [ JZ/LOOP ] ENDLOOP\n", opcodes);
  printf("%i-byte program\n", proglen);

  printf("pipe urandom to stdin\n");

  unsigned int i = 0;
  for (i = 0; i<proglen;i++){
    char a = (rand()/(RAND_MAX>>8));
    prog[i] = a%opcodes;
  }

  unsigned int ip = 0;
  unsigned int dp = 0;



//  printf("Sleep 3\n");
//  system("sleep 3");

  unsigned int nextip = 9999999;

  unsigned int progcycles = 2048;
  unsigned int progctr = 0;
  for (progctr = 0; progctr < progcycles; progctr++) {
    if (nextip != 9999999) {
      ip = nextip;
      nextip = 9999999;
    } else {
      ip++;
    }

    ip = ip % proglen;

//    dp++; // testing
    if (prog[ip] == 1) {
      //printf("<\n");
      if (dp > 0) {
        dp--; }
//      } else {
//        dp = datalen - 1;
//      }
    } else if (prog[ip] == 2) {
      //printf(">\n");
      if (dp < datalen - 1) { dp++; } // data pointer can stick at edge
//    } else if (prog[ip] == 1) {
//      dp+=wX;
//    } else if (prog[ip] == 2) {
//      if (dp < wX) { dp = (proglen - wX) + dp; } else { dp-=wX; }
    } else if (prog[ip] == 3) {
      //printf("-\n");
      if (data[dp] > 0) {
        data[dp]--;
      } // else { data[dp] = 255; }
    } else if ( prog[ip] == 4) {
      if (data[dp] < 255) { // 10 = opcodes - 1 (11 - 1)
      //printf("+\n");
        data[dp]++;
      } // else { data[dp] = 0; }
/*    } else if (prog[ip] == 5) {
      char r = (rand()/(RAND_MAX>>8))%256;
      data[dp] = r;
//      ray_ctr = 0; // got randomness no rays
    } else if (prog[ip] == 6) {
      tape[tape_index] = data[dp];
      tape_index++;
      if (tape_index == wX*3) { tape_index = 0; } */
    } else if (prog[ip] == 5) {
      if (data[dp] == 0) {
        // jump to ] if 0 or >0 choose
        //printf("[\n");
        unsigned int Tip = ip;
        Tip++;
        unsigned int opens = 1;
        while ((prog[Tip] != 6 || opens > 1) && Tip != (ip+1)%proglen) {
          if (prog[Tip] == 6) { if (opens > 1) { opens--; } else {break;} }
          if (prog[Tip] == 5)  { opens++; }
          if (Tip = proglen) { Tip = 0; } else { Tip++; }
        }
        nextip = (Tip+1)%proglen;
      }
    } else if (prog[ip] == 6) {
      // jump to [ if !0 or 0 choose
      //printf("]\n");
      if (data[dp] > 0) {
        unsigned int Tip = ip;
        if (ip > 0) { Tip--; } else { Tip = proglen - 1; }
        unsigned int closes = 1;
        while ((prog[Tip] != 5 || closes > 1) && Tip != (ip+1)%proglen) {
          if (prog[Tip] == 6) { closes++; }
          if (prog[Tip] == 5)  { if (closes > 1) { closes--; } else {break;} }
          if (Tip == 0) { Tip = proglen; }
          Tip--;
        }
        nextip = (Tip+1)%proglen;
      }
    }
  }
  showprog(&prog, &opcd, proglen, ip, dp, &data);
printf ("bf eval complete (debug)\n");

      } // prog running part ends



//    printf("sniff out win crash 3\n");

    if (whichsound == 0) {
      whichsound = 1;
      lastSoundBuf = 1;
      printf("Starting the buffers\n");
      //SDL_Delay(1000); // make sure intro noise is over
      Mix_ChannelFinished(mcfcb);
      channel = Mix_PlayChannel(-1, soundBuffer, 0);
      if(channel < 0) {
        fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
      }
      wavePos = 0;
      targetWavePos = 0;
    }


//    printf("whichsound = %i\n", whichsound);
    int ows = whichsound;
     
         if (soundSource > 0 && (lastSoundBuf != ows || avgOrSnapshot == 1)) { // load views for playing as sound
         int *tist = isoundtable;
         Uint8 *tuist = uisoundtable;
         float *fist = fsoundtable;
 //        printf("try to soundsource it\n");
 //        printf ("%i %i %i\n", uisoundtable, isoundtable, fsoundtable);
        if (avgOrSnapshot == 0 || firstsoundavg == 1) { // using snapshots, load table
          firstsoundavg = 0;
           if (uisoundtable != 0) {
             for (j = 0; j < gridcols; j++) {
               for (i = 0; i < gridrows; i++) {
                 soundVals[j][i] = (float) *uisoundtable;
 //              printf("%i",*uisoundtable);
                 uisoundtable++;
               }
             }
 //          printf("\n");
           } else if (fsoundtable != 0) {
           // t_table = fsoundtable; // not sure this is equivalent to, 
                                     // and would be faster than:
             for (j = 0; j < gridcols; j++) {
               for (i = 0; i < gridrows; i++) {
                 soundVals[j][i] = (float) *fsoundtable;
                 fsoundtable++;
               }
             }
           } else {
             for (j = 0; j < gridcols; j++) {
               for (i = 0; i < gridrows; i++) {
                 soundVals[j][i] = (float) *isoundtable;
                 isoundtable++;
               }
             }
           }
         } else if (avgOrSnapshot == 1) {
           // take averages instead
           if (uisoundtable != 0) {
             for (j = 0; j < gridcols; j++) {
               for (i = 0; i < gridrows; i++) {
                 soundVals[j][i] += (float) *uisoundtable;
                 soundVals[j][i] = soundVals[j][i] / 2.0f;
 //              printf("%i",*uisoundtable);
                 uisoundtable++;
               }
             }
 //          printf("\n");
           } else if (fsoundtable != 0) {
           // t_table = fsoundtable; // not sure this is equivalent to, 
                                     // and would be faster than:
             for (j = 0; j < gridcols; j++) {
               for (i = 0; i < gridrows; i++) {
                 soundVals[j][i] += (float) *fsoundtable;
                 soundVals[j][i] = soundVals[j][i] / 2.0f;
                 fsoundtable++;
               }
             }
           } else {
             for (j = 0; j < gridcols; j++) {
               for (i = 0; i < gridrows; i++) {
                 soundVals[j][i] += (float) *isoundtable;
                 soundVals[j][i] = soundVals[j][i] / 2.0f;
                 isoundtable++;
               }
             }
           }
         } // end avgOrSnapshot
         isoundtable = tist;
         uisoundtable = tuist;
         fsoundtable = fist;
         }
         
 //    printf("whichsound = %i\n", whichsound);
 

    if (lastSoundBuf != ows) {
/*      if (soundSource == 0) { // play votes
        printf("load buffer %i with %i votes\n", ows, waveVotesCtr);
      } else if (soundSource == 1) { // play sound rewards
        printf("load buffer %i with %i cells' sound rewards compressed to %i samples\n",ows,popsize,waveVotesCtr);
      } */
//      waveVotesCtr = 0;

      targetWavePos += 4000;
      while (targetWavePos >= (*sound).alen) {
        targetWavePos = targetWavePos - (*sound).alen; // yay
        //targetWavePos = soundoffs; // for if not while and wrong i guess
      }





      Mix_Chunk *whatsound = 0;

      if (ows == 1) { whatsound = soundBuffer; } else if (ows == 2) { whatsound = soundBuffer2; }


      if (soundSource == 0) { // play voted for sound wave
      for (p = 0; p < 4000; p++) {
        unsigned int hiVote = 0;
        unsigned int hiScore = 0;
        unsigned int P = 0;
        for (P = 0; P < 256; P++) {
          if(waveVotes[p][P] > hiScore) { hiVote = P;hiScore= waveVotes[p][P];}
        }


        if (hiScore > 0){ 
          unsigned int oldHiVote = hiVote;

          for (P = 0; P < 256; P++) {
            if(waveVotes[p][P] == hiScore && P != oldHiVote) { 
              hiVote += P;
              hiVote = hiVote >> 1;
            } // average top scoring bytes together
          }
        }

        Uint16 * vip=((*whatsound).abuf);
        vip[p] = ((Uint16) hiVote)*256;
//    printf("sniff out win crash 4\n");

  
        }
       unsigned int P; // too bad it goes 1 too high to be a uint8. aha
       for (p = 0; p < 4000; p++) {
         for (P = 0; P < 256; P++) { // do this only if playing votes
           waveVotes[p][P] = 0;      // boring
         }
       }
       } else if (soundSource > 0) { // play views as sound
 //        printf("lsfv\n");
         loadSoundFromView(whatsound, soundVals, waveStep, minsound, maxsound);
 //        printf("lsfv done\n");
 
       }
       lastSoundBuf = ows;
 
           if (soundSource > 0 && avgOrSnapshot == 1) {
             for (j = 0; j < gridcols; j++) {
               for (i = 0; i < gridrows; i++) {
                 soundVals[j][i] = 0;
               }
             }
             firstsoundavg = 1; 
           }
     }
 
//     waveVotesCtr += neuralsubruns;
 
     highgen = 0; // we need this before here to make the generation count sound
     avggen = 0;
 
     if ((view >= 5 && view <= 9) || (soundSource >= 6 && soundSource <= 10) || view == 99) {
       for (i = 0; i < gridrows; i++) {
         for (j = 0; j < gridcols; j++) {
           if (view == 5 || view == 99 || soundSource == 6) { actions_view[j][i] = 0; }
           if (view == 6 || view == 99 || soundSource == 7) { actions_view2[j][i] = 0;}
           if (view == 7 || view == 99 || soundSource == 8) { actions_view3[j][i] = 0;}
           if (view == 8 || view == 99 || soundSource == 9) { actions_view4[j][i] = 0;}
           if (view == 9 || view == 99 || soundSource == 10) { actions_view5[j][i] = 0;}
         }
       }
     }
 
     if (soundSource == 15 || view == 14 || view == 99) {
       for (i = 0; i < gridrows; i++) {
         for (j = 0; j < gridcols; j++) { // damn
           soundRewards[j][i] = 0; // zero this too
          }
        }
      }
 
     if (soundSource == 17 || view == 16 || view == 17 || view == 99) {
       for (i = 0; i < gridrows; i++) {
         for (j = 0; j < gridcols; j++) { // damn
           selfmod[j][i] = 0; // wow
           // most tables i'll want to be sure i zero between making the sound
           // waves and doing the grid, not between doing the grid and the sound
           // waves which is also when i display them, and i may have been zeroing
           // some between where i display them and where i make them into sound
           // now so look out
          }
        }
     }
 
 //    printf("whichsound = %i\n", whichsound);
 
//    printf("whichsound = %i\n", whichsound);
     for (run = 0; run < 4; run++) { // eval in reverse half the time
                                    // to get rid of the 'wind' from
                                    // not using enough temp grids to
                                    // make all the actions fair
                                    // in both directions
                                    // all the time

//      printf("run %i\n", run);



      for (i = starty; i != lasty; i+=inc) {
        for (j = startx; j != lastx; j+=inc) {
//      for (i = 0; i < gridrows; i++) {
//        for (j = 0; j < gridcols; j++) {
          signed int newcell;
          Uint8 *thisdna = DNA[j][i]; // hmm i use this in brain run too now
          if (run == 0) { // dna run

//    printf("sniff out win crash 5.2\n");

//            offspring[j][i][0] = 0;
//            offspring[j][i][1] = 255;
//            newskips[j][i] = 0;
            if (DNA_on) {
//            dnarun[j][i] = newcell;


            if (skips[j][i] > 7) { // printf("skip");
         if (skips[j][i] > 7) {         
              skipsctr++;
              // skip makes goto's now, like direction sense sorta (no see below)

              //DNA_IP[j][i] += (skips[j][i]%8)*2;
              //while (DNA_IP[j][i] >= DNA_Length) {DNA_IP[j][i] -= DNA_Length;} 
              // ^ since Pokes and Fights both push out a critter's IP, and NOP
              //   doesn't except at this stage, and is a defense against Fight
              //   ... this line would turn NOP's into JMP's... without it, they
              //   could NOP twice to stun themselves into spending an extra
              //   frame on the defensive NOP.
              newskips[j][i] = skips[j][i] - 8;  }
            } else {
              if (skips[j][i] > 0) {
                newskips[j][i] = 0;
              }
            
            if (sexctr[j][i]>0) { sexctr[j][i]--; }


              int opCtr;
              for (opCtr = 0; opCtr < opcodesPerFrame; opCtr++) {
              Uint8 op = thisdna[DNA_IP[j][i]];
              if (op > 5) { op = op % 6; } // yay 6, number of opcodes + 1,
              Uint8 arg = thisdna[DNA_IP[j][i]+1];//+DNA_DP[j][i];                 // again
              Uint8 arg2 = thisdna[DNA_IP[j][i]+2];//+DNA_DP[j][i];
              Uint8 arg3 = thisdna[DNA_IP[j][i]+3];

//              while (arg3 > 4) { arg -= 4; sexctr[j][i] += sexoperandpersistance; }

//              op = 0; // no
              if (op != 0) {
                Uint8 *brainptr = Brains[j][i];
                Uint8 syn;
                Uint8 freesynapse = 255; // look out
                if (op == 1) { // new synapse / add synapse
                  if (arg == 0) { arg = 1; }   
                  if (arg2 == 0) { arg2 = 1; } // 0 is no neuron
                  for (syn = 2; syn < num_of_synapses; syn+=4) {
                    if (brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1))) + syn] == 0) {
                      freesynapse = syn;
                      break;
                    }
                  }
                  if (freesynapse < 255) { // room on the neuron for a synapse
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse] = (arg2%num_of_neurons)+1;
                    // id of neuron new synapse signals firing of
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse+1] = arg3&3;
                    // type of synapse (0 to 3)
//                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse+2] = (arg3>>6)+1;
// 		      ^ weights up to 4
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse+2] = (arg3>>5)+1;
//		    ^ weights up to 8
                    // weight of synapse (1 to 8) 
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse+3] = 32;
                    // reset plasticity
                  }
                } else if (op == 2) { // new neuron
                  if (neuroncount[j][i] < num_of_neurons) {
                    neuroncount[j][i] += 1;
                    brainptr[(num_of_synapses*neuroncount[j][i])] = arg2;
                    // zero potential on 'new' neuron (or should it be arg3)
                    Uint8 newthresh = arg;
                    if (newthresh == 0) { newthresh = 1; }
                    brainptr[(num_of_synapses*neuroncount[j][i])+1] = newthresh;
                    // set threshold of 'new' neuron
                  }
                } else if (op == 3) { // pull neuron
                  //if (neuroncount[j][i] > cortical_neurons) {
                  if (neuroncount[j][i] > cortical_neurons) {
			  neuroncount[j][i] -= 1;
                  }
                } else if (op == 4) { // pull synapse
                  Uint8 lastsynapse = 255;
                  if (arg == 0) { arg = 1; }
                  for (syn = 2; syn < num_of_synapses; syn+=4) {
                    if (brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1))) + syn] == 0) {
                      break;
                    }
                    lastsynapse = syn;
                  } 
                  if (lastsynapse < 255) { // found a last synapse on that neuron (also not the first)
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+lastsynapse] = 0;
                    // deactivate it 
                  }
                } else if (op == 5) { // alter neuron
                    
                      if (arg == 0) {arg = 1;} // 0 is no neuron
                      brainptr[((num_of_synapses*(arg%(neuroncount[j][i]+1))))] = arg2;
                      // arg 1 is neuron to change, arg2 is new potential

                      if (arg%(neuroncount[j][i]+1) != 71)  { // dont change thresh on neur 71
                                        // for sound voting must
                                        // stay 255, 72 is drug
                                        // motor now hahaha

                        if (arg3 == 0) { arg3 = 1; } // 0 is no threshold
                        brainptr[((num_of_synapses*(arg%(neuroncount[j][i]+1))))+1] = arg3;
                        // arg 3 is new threshold
                      }
                    
                
                  
              }} else { // dna nop causes half a stall and helps defend in fights

                newskips[j][i] += arg3>>5; // well on average...
//                printf("%i, %i nops\n", j, i);
                nops += 1;
                if (soundSource == 10 || ((view == 9 || view == 99) && t == drawevery-1)) { actions_view5[j][i] += 1; } 
              }

              //if (dnarun[j][i] <= 0) { dnarun[j][i] = 1; }

              DNA_IP[j][i]+=4; // this should have been at the end all along or
                               // i skip the first byte but it can be mutated
                               // still. er
              while (DNA_IP[j][i] >= DNA_Length) { DNA_IP[j][i] -= DNA_Length; }
              
              } // repeat opcodesPerFrame times
              // end DNA run
            } // end indented skip check
            } // else { } // if DNA_on is off *unindented
          } else if (run == 1) {  // brains run
//    printf("sniff out win crash 5.4\n");
            newcell = grid[j][i];

            newcell *= 1.2; // fade

            if (DNA_on && ((rand()%64)) < (newcell+16)) {

		turnsTaken += 1;

            Uint8 destx = 0; // NOTE if you ever need a grid bigger than
            Uint8 desty = 0; // 254x254, make these ints!
                             // and initialize offspring[] initial
                             // values to -1 instead of 255 and
                             // change the check in the breed run
                             // accordingly... and the set in the
                             // dna run... ok!


            Uint8 acts = 0;

            Uint8 *brainptr = Brains[j][i];

            Uint8 dir;
            Uint8 op;

            // this is pretty important now v
            Uint8 opt;
            Uint8 dirt;
            Uint8 jt;
            Uint8 it;
            for (opt = 0; opt < 4; opt++) {
              for (dirt = 0; dirt < 8; dirt++) {
                actions[opt][dirt] = 0; // hope this works
                // another place i should zero or clear four bytes at a time
              }
            }

            soundoffs = (unsigned int) targetWavePos + (unsigned int) wavePos;
//            if (theVote>0 && theVote < 100) { //printf("soundoffs = %i\n(*sound).alen = %i\n", soundoffs, (*sound).alen);}
//              printf("theVote = %i\n", theVote);
//            }
            while (soundoffs >= (*sound).alen) { soundoffs -= (*sound).alen; }
  //          printf("what\n");

            unsigned int wantstoinput = 0;
            unsigned int wantstooutput = 0;

            int neuralsubrunctr;
            for (neuralsubrunctr = 0; neuralsubrunctr < neuralsubruns; neuralsubrunctr++)
            {
            dir = 0;
            op = 0;
            int idx = 0;

//    printf("sniff out win crash 5.41\n");

            if (inputs[j][i] > 0) { // flash brainfuck program on sense neurons
              if (inputs[j][i] < 4) { inputs[j][i] -= 1; } else { inputs[j][i] = 3; } // for 2 turns
              for (op=0;op<4;op++) {
                for (dir=0;dir<8;dir++) {            
                  idx += num_of_synapses; // start at neuron 1 (hardwired sensory)
                  int amt = prog[(op*8)+dir]*2;
//                printf("sneur %i pot %i add amt %i", (op*4+dir)+1, brainptr[idx], amt);
                  if ((Sint16) brainptr[idx] + amt > 255) { brainptr[idx] = 255; }
                                                    else { brainptr[idx] += (Uint8) amt; }
                  idx += num_of_synapses;
                  }
              } 
            } else {
              for (op=0;op<4;op++) {
                for (dir=0;dir<8;dir++) {            
                  idx += num_of_synapses; // start at neuron 1 (hardwired sensory)
                  int amt = stimuli[j][i][op][dir];
                  //                printf("sneur %i pot %i add amt %i", (op*4+dir)+1, brainptr[idx], amt);
                  if ((Sint16) brainptr[idx] + amt > 255) { brainptr[idx] = 255; }
                                                    else { brainptr[idx] += (Uint8) amt; }
                  idx += num_of_synapses;
                  }
              } // fastest way to load sensor neurons of defaultbrain
                // if you change its wiring change this too... to
                // look the right places 
//    printf("sniff out win crash 5.42\n");
            }
                                // this isn't finished... when i do soundreward, it should
                                // also be against all the bytes the cell has to cover here
                                // an average of them or each of them or someting dumb like
                                // this. only for populations smaller than the sound (4000
                                // samples right now)

//            printf ("ok what\n");
//    printf("sniff out win crash 5.43\n");
            idx += num_of_synapses;
            Uint8 amt = (Uint8) newcell >> 3;
//                printf("sneur %i pot %i add amt %i", (op*4+dir)+1, brainptr[idx], amt);
            if ((Sint16) brainptr[idx] + amt > 255) { brainptr[idx] = 255; }
                                            else { brainptr[idx] += (Uint8) amt; }
            // temperature sense (annoying code duplication indicated)

//    printf("sniff out win crash 5.44\n");            
            // neuron 65 is temperature sense... neuron 70 is the new dna
            // stun one... so go ahead six more neurons here and we'll treat
            // neuron 71 as the one whose potential we use as votes for sound
            // waves (its potential out of threshold in 255 steps)
            // SOUND VOTING PART.

            if (neuroncount[j][i]>70) {
//            printf("sdf\n");

            idx = num_of_synapses*71; // to neuron 71 i hope
            unsigned int theVote;
            if (brainptr[idx] > 0) {
              float uptoeightbitsok = (float) brainptr[idx];
              if (uptoeightbitsok > (float) brainptr[idx+1]) { theVote = 255; } else{
                theVote = (unsigned int) ((uptoeightbitsok / (float) brainptr[idx+1]) * 255.0f);
              }
//              if (theVote > 300) {
//                printf("uptoeightbitsok = %f\n(float) brainptr[idx+1] = %f\n(unsigned int) brainptr[idx+1] = %i\ntheVote = %i\n\n",uptoeightbitsok,(float) brainptr[idx+1],(unsigned int) brainptr[idx+1], theVote);
//              }
            } else { theVote = 0; }
//    printf("sniff out win crash 5.45\n");
//            if (theVote>0) { printf("wavepos = %i\ntheVote = %i\n", wavePos, theVote);}
            waveVotes[(unsigned int) wavePos][theVote] += 1;
            if (waveStep >= 1.0f) {
              unsigned int aaa; // stretch votes from undersized populations
              for (aaa=(unsigned int)oldwavepos;aaa!=(unsigned int)wavePos;aaa+=inc) {     // to fit the sound, sheesh
                waveVotes[(unsigned int)aaa][theVote] += 1; // all from him then
                if (aaa < 1) {break;}
              }
              // i dont think this should ever happen anyway v just tryna find
              // this sound bug with undersize pops
              // ok it does happen good, this fills the end of the buffer with
              // the last cell counted's vote
              if ((wavePos + curWaveStep >= (*soundBuffer).alen && wavePos < (*soundBuffer).alen)||(wavePos + curWaveStep < 0 && wavePos >= 1)) {
                for (aaa=(unsigned int)wavePos+inc;aaa!=(unsigned int)(*soundBuffer).alen;aaa+=inc) {     // to fit the sound, sheesh
                  waveVotes[(unsigned int)aaa][theVote] += 1; // and fill the end
//                  printf("aaa = %i oldwavepos = %f wavePos = %f theVote = %i\n", aaa, oldwavepos, wavePos, theVote);
                }  
              }  
            }
            float soundreward = 0;
            soundreward = (float) (*sound).abuf[soundoffs];
            float ohno;

           // if (((*sound).abuf[soundoffs] == 0 || (*sound).abuf[soundoffs] == 255) || (theVote > 0 && theVote < 255) ) {
           	 if ( (theVote > 0 && theVote < 255) ) {
              if ((float)theVote > soundreward) {
                ohno = (float)((float)theVote-soundreward);	
                //if (ohno < 48) { 
                soundreward = 0 - ohno;
                //}
//             printf("soundreward = %f\n", soundreward);
//    printf("sniff out win crash 5.46\n");
              } else {
                ohno = (float)(soundreward-(float)theVote);
                //if (ohno < 48) {
                soundreward = 0 - ohno; //} // damn is float
                                                          // so no bitshift
//             printf("soundreward = %f\n", soundreward);

              }

//    printf("sniff out win crash 5.47\n");

              if (ohno <128.0f) {
                soundreward += 16.0f-( (ohno/8.0f) );
              }
              
                            if (ohno <96.0f) {
                soundreward += 24.0f-( (ohno/3.0f) );
              }

              if (ohno <64.0f) {
                soundreward += 32.0f-( (ohno/2.0f) );
              }


              if (ohno <48.0f) {
                soundreward += 48.0f-( (ohno/2.0f) );
              }

              if (ohno < 24.0f) {
                soundreward += 48.0f-( (ohno/2.0f) );
                // if they were within 3.999 in either dir of the target byte
                // we give em up to double the energy reward for proximity to
                // it
              }
              
              if (ohno < 16.0f) {
                soundreward += 56.0f-((ohno));
              }

              if (ohno < 8.0f) {
                soundreward += 64.0f-((ohno*2.0f));
              }

              if (ohno < 5.0f) {
                soundreward += 96.0f-((ohno*10.0f));
              }



//    printf("sniff out win crash 5.48\n");
//                if (soundreward > 11.0f) {printf("soundreward = %f\n", soundreward);}

//            if (theVote != 0) { printf ("targetwavePos = %i\nwavePos = %f\ntheVote = %i\nohno = %f\nsoundreward = %f\n(unsigned int) (*sound).abuf[soundoffs] = %i\n\n", (unsigned int) targetWavePos, wavePos, theVote, ohno, soundreward, (unsigned int) (*sound).abuf[soundoffs]);}
//             printf("soundreward = %f\n\n", soundreward);
//             printf("theVote = %i\n", theVote);
            
//            printf("Whut\n");
            } else { soundreward = -127.0f;}
                        
/*            if (newcell > soundreward && (unsigned int) (newcell + soundreward) <= 255) {
              newcell += soundreward;
            } else if (newcell > soundreward) { newcell = 0; } else { newcell = 255; } */
            // oops ^
            if (soundreward < 0 && newcell < 0.0f-soundreward) { newcell = 0; } else {
              if ((unsigned int) (newcell + soundreward) <= 255) {
                newcell += (Sint16) soundreward;
              }  else { newcell = 255; }
            }            
            avgSoundReward += soundreward;

            if (soundSource == 15 || ((view == 14 || view == 99) && t == drawevery-1)) { // no big reason to only do this then
if (soundreward+128.0f <= 255) {
              soundRewards[j][i] = (soundreward+128.0f); // for display
} else { soundRewards[j][i] = 255; }
            }
//            printf("theVote = %i\n\n", theVote); // god
//            if (j == 40 && i == 40) {
//            printf("%f %f %i\n", soundRewards[j][i], soundreward,newcell); }
            } else {  } //nothing. we clear this later
//    printf("sniff out win crash 5.49\n");            
            Uint8 neur;
            Uint8 syn;
            Uint8 pot;
//            Uint8 thresh;
            Uint8 thresh;
    
    // load neighbours temps
    idx = num_of_synapses*77; // start at neuron 77 (hardwired sensory)
  			  if (i == 0) { up = gridlasty; } else { up = i-1; }
              if (i == gridlasty) { down = 0; } else { down = i+1; }
              if (j == 0) { left = gridlastx; } else { left = j-1; }
              if (j == gridlastx) { right = 0; } else { right = j+1; }
    
    if (brainptr[idx] + grid[left][up] > 255) {brainptr[idx] = 255;} else {brainptr[idx] += grid[left][up];}
	idx += num_of_synapses;idx += num_of_synapses;
    if (brainptr[idx] + grid[left][i] > 255) {brainptr[idx] = 255;} else {brainptr[idx] += grid[left][i];}
	idx += num_of_synapses;idx += num_of_synapses;
    if (brainptr[idx] + grid[left][down] > 255) {brainptr[idx] = 255;} else {brainptr[idx] += grid[left][down];}
	idx += num_of_synapses;idx += num_of_synapses;
    if (brainptr[idx] + grid[j][down] > 255) {brainptr[idx] = 255;} else {brainptr[idx] += grid[j][down];}
	idx += num_of_synapses;idx += num_of_synapses;
    if (brainptr[idx] + grid[right][down] > 255) {brainptr[idx] = 255;} else {brainptr[idx] += grid[right][down];}
	idx += num_of_synapses;idx += num_of_synapses;
    if (brainptr[idx] + grid[right][i] > 255) {brainptr[idx] = 255;} else {brainptr[idx] += grid[right][i];}
	idx += num_of_synapses;idx += num_of_synapses;
    if (brainptr[idx] + grid[right][up] > 255) {brainptr[idx] = 255;} else {brainptr[idx] += grid[right][up];}
	idx += num_of_synapses;idx += num_of_synapses;
    if (brainptr[idx] + grid[j][up] > 255) {brainptr[idx] = 255;} else {brainptr[idx] += grid[j][up];}
	


                  
	idx = num_of_synapses;

//            printf("%i\n", neuroncount[j][i]);
            for (neur = 0; neur <= num_of_neurons; neur++) { did_fire[neur] = 0;}
            // ^ optimize this in every version only load and clear to 
            //   neuroncount

//    printf("sniff out win crash 5.49.1\n");            

            if (i == 0 && j == 0) { for (neur = 0; neur <= num_of_neurons; neur++) { CellZero_did_fire[neur] = 0;} }
            if (i == 0 && j == 0) { for (neur = 0; neur <= num_of_neurons; neur++) { CellZero_did_fire[neur] = 0;} }


            for (neur = 1; neur <= neuroncount[j][i]; neur++) {
              if (brainptr[idx] >= brainptr[idx+1]) { // neuron over threshold
                did_fire[neur] = brainptr[idx+1]/brainptr[idx]; // fire
			Uint8 fctr;
            
		    if (did_fire[neur] > 1) { for(fctr = did_fire[neur]; fctr > 1; fctr--) {
		
                // pull synapse
              Uint8 lastsynapse = 255;
              Uint8 *brainptr = Brains[j][i];
                Uint8 syn;
                Uint8 freesynapse = 255; // look out
                Uint16 arg = neur;
                
                  if (arg == 0) { arg = 1; }
                  for (syn = 2; syn < num_of_synapses; syn+=4) {
                    if (brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1))) + syn] == 0) {
                      break;
                    }
                    lastsynapse = syn;
                  } 
                  if (lastsynapse < 255) { // found a last synapse on that neuron (also not the first)
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+lastsynapse] = 0;
                    // deactivate it 
                    newcell+=15;
                  }
                } } 
                if (i == 0 && j == 0) { CellZero_did_fire[neur] = 1;} 
//                if (brainptr[idx+1] == 0) { printf("THRESHOLD BORK pos %i,%i neur %i/%i offset %i\n", j, i, neur, neuroncount[j][i], idx);}
                brainptr[idx] = brainptr[idx] % brainptr[idx+1]; // - brainptr[idx+1];
//                brainptr[idx] = brainptr[idx] - brainptr[idx+1];                
                                   // ^ ... mod by threshold here i guess
                                   // if it's not already way too slow or
                                   // just use 0... or just use minus and let
                                   // potentials take time to clear out why not

              }  else if (brainptr[idx] == 0) { //did_fire[neur] = 0;
              // add synapse
                Uint8 *brainptr = Brains[j][i];
                Uint8 syn;
                Uint8 freesynapse = 255; // look out
                Uint16 arg = neur;
                Uint16 arg2 = 71;
                Uint8 arg3 = 64;
                if (arg == 0) { arg = 1; }   
                  if (arg2 == 0) { arg2 = 1; } // 0 is no neuron
                  for (syn = 2; syn < num_of_synapses; syn+=4) {
                    if (brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1))) + syn] == 0) {
                      freesynapse = syn;
                      break;
                    }
                  }
                  if (freesynapse < 255) { // room on the neuron for a synapse
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse] = (arg2%num_of_neurons)+1;
                    // id of neuron new synapse signals firing of
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse+1] = arg3&3;
                    // type of synapse (0 to 3)
//                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse+2] = (arg3>>6)+1;
// 		      ^ weights up to 4
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse+2] = (arg3>>5)+1;
//		    ^ weights up to 8
                    // weight of synapse (1 to 8) 
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse+3] = 32;
                    // reset plasticity
                    newcell+=15;
                  } }
            
//    printf("sniff out win crash 5.49.2\n");            

//                if (neur > 65 ) { printf ("pot on neur %i is %i\n",neur,brainptr[idx]);}
//                if (did_fire[neur] && neur > 65) { printf ("fired\n"); }

              idx += num_of_synapses;
            }
//    printf("sniff out win crash 5.50\n");            
            idx = num_of_synapses;
            for (neur = 1; neur <= neuroncount[j][i]; neur++) {
//              printf("idx %i neuron #%i pot %i thresh %i\n", idx, neur, brainptr[idx], brainptr[idx+1]);
                int neuridx = idx;
                pot = brainptr[idx];
                // thresh = brainptr[idx+1]; 
                if (pot > 0) { if (stims[j][i] > 0) { pot = (Uint8) ( (float) pot * (0.8f+((float) stims[j][i]/224.0f)+((((float)newcell)/255.0f)/7.0f)) ); } // decay...
                  else { pot = (Uint8) ( (float) pot * (0.845f+((((float)newcell)/255.0f)/7.0f)) ); } // decay...
                } // ^if not on drugs
                // decay is adjusted by temperature... lower decay at more energy
                // at 0 temp, decay is 0.845f... at 255 temp, decay is 0.995

              if (brainptr[idx+2] == 0) {
//                brainptr[idx] = 0; // dont zero it if disconnected
                                     // this kills the potential addneuron adds
                brainptr[neuridx] = pot; // set new potential
                idx += num_of_synapses;
//                printf("no synapses to neuron %i (squash this printf after eventually seeing it ok)\n", neur);
//                break; // ok
              } else { // decide to decay potential on even disconnected
                         // neurons just for display purposes

                idx += 2;
                for (syn = 2; syn < num_of_synapses; syn+=4) {
                  // now brainptr is at the start of a synapse
                  if (brainptr[idx] == 0) { //idx+=(num_of_synapses-syn); 
                                              break;  // making idx = neuridx+num_of_synapses below should handle realignment
                                                   // synapses are ordered
                                                   // with no spaces like
                                                   // neurons ... so stop
                                                   // looking when you hit
                                                   // an unconnected one
                  }
					Sint16 bidiplasteffect = 0;
					bidiplasteffect += did_fire[neur];
                  	bidiplasteffect -= did_fire[brainptr[idx]];
                    

                  if (brainptr[idx+1] > 1 && did_fire[neur]) { // types 2 and 3 are plastic
                    if (brainptr[idx+1] & 1) {  // inhib
                      if (brainptr[idx+3] < 65-bidiplasteffect) {brainptr[idx+3]+=bidiplasteffect;} else
                                                 {brainptr[idx+3]=64;} // plast
                    } else { // excit
                      if (brainptr[idx+3] > bidiplasteffect) {brainptr[idx+3]-=bidiplasteffect;} else
                                               {brainptr[idx+3]=0;} // plast
                    }
                  } 

                  if (did_fire[neur]) { //  bidirectional synapses
                  	newpots[brainptr[idx]] += brainptr[idx+2] * (brainptr[idx+3]-32) * did_fire[neur];
                  }
                  	


                  if (did_fire[brainptr[idx]]) {
                    int amt;
                    if (brainptr[idx+1] > 1) { // types 2 and 3 are plastic
                      amt = ((Sint16) brainptr[idx+2]*((Sint16) brainptr[idx+3]-32))*did_fire[neur];
                      if (brainptr[idx+1] & 1) {
                        if (brainptr[idx+3] > bidiplasteffect) {brainptr[idx+3]-=bidiplasteffect;} else
                                                 {brainptr[idx+3]=0;} // plast
                        // this is weird... i used plastic synapses not plastic
                        // neurons sort of by accident, well with inhib/excit
                        // neurons i could have normal plastic synapses or
                        // vice versa. so i'll do plasticity the other way
                        // when the host neuron fires too or it will only
                        // drift to min or max depending if the synapse is
                        // inhib or excit... we do this right above this block

                      } else {
                        if (brainptr[idx+3] < 65-bidiplasteffect) {brainptr[idx+3]+=bidiplasteffect;} else
                                                   {brainptr[idx+3]=64;} // plast
                      }
                    } else {
                      amt = (Sint16) brainptr[idx+2]*did_fire[neur];
                    }
                    if (brainptr[idx+1] & 1) {
                      amt *= -1; // types 1 and 3 are inhibitory...
                    }
                    if ((Sint16) pot + amt < 0) { pot = 0; }
                    else if ((Sint16) pot + amt > 255) { pot = 255;
                    } else { pot = (Uint8) ((Sint16) pot + amt); } // need these casts or not
                  }
                  idx += 4; // next synapse
                }

                brainptr[neuridx] = pot; // set new potential
                idx = neuridx + num_of_synapses;
              } // decay potential even on disconnected neurons
              // well really we zero it wtf. ok lets not anymore
              // zero it that is

            }
            
            idx = num_of_synapses;
				unsigned int neuridx = idx;
                        for (neur = 1; neur <= neuroncount[j][i]; neur++) {
                if (brainptr[neuridx] < newpots[neur]) { brainptr[neuridx] = 0; }
                else if (brainptr[neuridx] + newpots[neur] > 255) { brainptr[neuridx] = 255; }
                else { brainptr[neuridx] += newpots[neur]; } // set new potential (bidirectional)
                neuridx += num_of_synapses;
						}
            
//    printf("sniff out win crash 5.51\n");            
            // scan motor neurons for firing to set acts and actions[]
            dir = 0;
            Uint8 mneur;
            op = 0;
            for (mneur = 2; mneur < 65; mneur += 2) {
//              brainptr += num_of_synapses;
              if (did_fire[mneur]) {
                acts = 1;
                actions[op][dir] = 1;
              } else {
                // actions[op][dir] = 0; // with neuralsubruns we
                                         // zero actions outside 
                                         // the loop first
              }
              dir += 1;
              if (dir == 8) {
                dir = 0;
                op += 1;
              }
              if (op == 4 && dir > 7) {
                printf("BORK?!\n"); // remove this block if not borking
              }
            } // fastest way to scan motor neurons of defaultbrain
              // if you change its wiring change this too... to
              // look the right places

            // breed mood output            
            if (did_fire[66]) { sexctr[j][i] += sexoperandpersistance; }

            // drug motor! wtf
            if (did_fire[72]) { if (stims[j][i] <= 245) { stims[j][i] += 10; } else {stims[j][i]=255;} if (newcell > 2) { newcell -= 3; } else { newcell = 0; } } // wow thirty. ok fifteen. ok ten

            // self modification
            if (did_fire[73] && !did_fire[74]) { newcell+=5; if (DNA_DP[j][i] > 0) {DNA_DP[j][i]--;} else {DNA_DP[j][i] = neuroncount[j][i]-1;} }
            if (did_fire[74] && !did_fire[73]) { newcell+=5; if (DNA_DP[j][i] < neuroncount[j][i]-1) {DNA_DP[j][i]++;} else {DNA_DP[j][i] = 0;} }
            if (did_fire[75]) {
            // pull synapse
              Uint8 lastsynapse = 255;
              Uint8 *brainptr = Brains[j][i];
                Uint8 syn;
                Uint8 freesynapse = 255; // look out
                Uint16 arg = DNA_DP[j][i];
                  if (arg == 0) { arg = 1; }
                  for (syn = 2; syn < num_of_synapses; syn+=4) {
                    if (brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1))) + syn] == 0) {
                      break;
                    }
                    lastsynapse = syn;
                  } 
                  if (lastsynapse < 255) { // found a last synapse on that neuron (also not the first)
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+lastsynapse] = 0;
                    // deactivate it 
                    newcell+=30;
                    generations[j][i] += 1;
                  }
 } 
            if (did_fire[76]) { 
            // add synapse (weight 1) to voter
                Uint8 *brainptr = Brains[j][i];
                Uint8 syn;
                Uint8 freesynapse = 255; // look out
                Uint16 arg = DNA_DP[j][i];
                Uint16 arg2 = rand()%256;
                Uint8 arg3 = 0|(did_fire[80]>0)|((did_fire[82]>0)*2);
                if (arg == 0) { arg = 1; }   
                  if (arg2 == 0) { arg2 = 1; } // 0 is no neuron
                  for (syn = 2; syn < num_of_synapses; syn+=4) {
                    if (brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1))) + syn] == 0) {
                      freesynapse = syn;
                      break;
                    }
                  }
                  if (freesynapse < 255) { // room on the neuron for a synapse
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse] = (arg2%num_of_neurons)+1;
                    // id of neuron new synapse signals firing of
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse+1] = arg3&3;
                    // type of synapse (0 to 3)
//                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse+2] = (arg3>>6)+1;
// 		      ^ weights up to 4
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse+2] = (arg3>>5)+1;
//		    ^ weights up to 8
                    // weight of synapse (1 to 8) 
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse+3] = 32;
                    // reset plasticity
                    newcell+=30;
                    generations[j][i] += 1;
                  }
                
            }  

            if (did_fire[78]) { 
            // add synapse (weight 4) to voter
                Uint8 *brainptr = Brains[j][i];
                Uint8 syn;
                Uint8 freesynapse = 255; // look out
                Uint16 arg = DNA_DP[j][i];
                Uint16 arg2 = rand()%256;
                Uint8 arg3 = 64|(did_fire[80]>0)|((did_fire[82]>0)*2);
                if (arg == 0) { arg = 1; }   
                  if (arg2 == 0) { arg2 = 1; } // 0 is no neuron
                  for (syn = 2; syn < num_of_synapses; syn+=4) {
                    if (brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1))) + syn] == 0) {
                      freesynapse = syn;
                      break;
                    }
                  }
                  if (freesynapse < 255) { // room on the neuron for a synapse
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse] = (arg2%num_of_neurons)+1;
                    // id of neuron new synapse signals firing of
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse+1] = arg3&3;
                    // type of synapse (0 to 3)
//                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse+2] = (arg3>>6)+1;
// 		      ^ weights up to 4
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse+2] = (arg3>>5)+1;
//		    ^ weights up to 8
                    // weight of synapse (1 to 8) 
                    brainptr[(num_of_synapses*(arg%(neuroncount[j][i]+1)))+freesynapse+3] = 32;
                    // reset plasticity
                    newcell+=30;
                    generations[j][i] += 1;
                  }
                
            }  

            // hahah weird last five motors, huh

            if (soundSource == 17 || soundSource == 18 || ((view == 16 || view == 17 || view == 99) && t == drawevery-1)) {
              if (did_fire[73]) { selfmod[j][i] += 1;}
              if (did_fire[74]) { selfmod[j][i] += 2;}
              if (did_fire[75]) { selfmod[j][i] += 4;}
              if (did_fire[76]) { selfmod[j][i] += 8;} // selfmod is just a view lol
              if (did_fire[78]) { selfmod[j][i] += 16;} // selfmod is just a view lol
              if (did_fire[80]) { selfmod[j][i] += 32;} // selfmod is just a view lol              
              if (did_fire[82]) { selfmod[j][i] += 32;} // selfmod is just a view lol              
            } 

            // I/O motors            
            if (did_fire[67]) { wantstoinput=1; acts = 1; } //printf("wants to input debug\n");}
            if (did_fire[68]) { wantstooutput=1; acts = 1; } // printf("wants to output debug\n");}

            neurskipsandstuns[j][i] = 0; // damn slow for nothing. should move 4 bytes at a time, how            
            if (did_fire[69]) { neuralskips += 1; neurskipsandstuns[j][i] += 1; DNA_IP[j][i] += 4*opcodesPerFrame ; while (DNA_IP[j][i] >= DNA_Length) { DNA_IP[j][i] -= DNA_Length; } }
            if (did_fire[70]) { if (newcell > 4) { newcell -= 5;  } else { newcell = 0; }neuralstuns += 1; neurskipsandstuns[j][i] += 3; newskips[j][i] += 3; } // ok you can stun it for 3/4 a turn the last 2
                                                        // skip and stun DNA

            idx = brainptr;

            } // so this should be where the neuralsubrun ends

            oldwavepos = wavePos;
            wavePos += curWaveStep; // oops do this outside
            
            if (acts) {
		int mod = 0;
            for (dir = 0; dir < 8; dir++) {            
              if (i == 0) { up = gridlasty; } else { up = i-1; }
              if (i == gridlasty) { down = 0; } else { down = i+1; }
              if (j == 0) { left = gridlastx; } else { left = j-1; }
              if (j == gridlastx) { right = 0; } else { right = j+1; }
                          
              if (dir == 0) {
                destx = left;
                desty = up;
              } else if (dir == 1) {
                destx = j;
                desty = up;
              } else if (dir == 2) {
                destx = right;
                desty = up;
              } else if (dir == 3) {
                destx = left;
                desty = i;
              } else if (dir == 4) {
                destx = right;
                desty = i;
              } else if (dir == 5) {
                destx = left;
                desty = down;
              } else if (dir == 6) {
                destx = j;
                desty = down;
              } else if (dir == 7) {
                destx = right;
                desty = down;
              }
//    printf("sniff out win crash 5.52\n");                          
              Uint8 wonafight = 0;
              if (actions[3][dir] == 1) { // fight
//                printf("fight\n");
                tstimuli[destx][desty][3][dir] += 16;
                if (soundSource == 9 || ((view == 8 || view == 99) && t == drawevery-1)) { actions_view4[destx][desty] += 1; }
                int high = grid[destx][desty];
                int low = grid[j][i];
                Uint8 *fighteedna = DNA[destx][desty];
                Uint8 fighteeop = fighteedna[DNA_IP[destx][desty]];
                if (fighteeop == 0) { low = low >> 1;   // double fight difficulty
                                                        // if victim is un busy
                                                        // (NOP) which also
                                                        // opens them to
                                                        // poke skips and
                                                        // communication... err
                                      if (soundSource == 9 || ((view == 8 || view == 99)&& t == drawevery-1)) { actions_view4[destx][desty] += 2; actions_view4[j][i] += 2; }
                }
                                                        
//                if (low > high) { int T = low; low = high; high = T; }
//                if ((rand()/randomdivisor) % (high+1) <= (low>>4)) { // win fight  (oops always uses high cell's odds)
                if ((rand()) % ((low>>2)+2) >= (rand()) % ((high<<2)+1)) { // win fight (~ 1/4 chance against cell of equal energy,
                                                                                                      // ~ 1/2 chance against cell of half energy,
                                                                                                      // ~ 1/10 chance against cell of double energy,
                                                                                                      // 2.5% chance against cell of 10x energy)
                  actions[1][dir] = 1; // suck too then, to breed et al
                  wonafight = 1;
                  wonfights += 1;
                  if (soundSource == 9 || ((view == 8 || view == 99) && t == drawevery-1)) { actions_view4[j][i] += 2; }
                  //dnarun_add[destx][desty] += biteAmount;
                } else {
//                  newcell -= biteAmount>>1;
                  //mod -= biteAmount; // they fight too much take off full biteAmount instead...
		   mod -= 70; 
//                  dnarun_sub[destx][desty] += biteAmount>>1; // both lose some energy for a lost fight                  
                  lostfights += 1;
                  if (fighteeop != 0) {
                    DNA_IP[destx][desty] += (dir+1)<<3; // lost fight signals the winner
                                                         // with a skip (up to
                                                         // 32 bytes), if it
                                                         // is not nopping
                    while(DNA_IP[destx][desty] > DNA_Length) { DNA_IP[destx][desty] -= DNA_Length; }
                  } else {
//                    newskips[destx][desty] += (dir+1); // this was a direction
                                     // sense to let the DNA know which side
                                     // a fight came from. but it causes too
                                     // much stunning of the DNA in the neural
                                     // versions, letting them avoid interacting
                                     // with the DNA and keeping it from
                                     // evolving. so instead we'll just add 2
                                     // and a stun will only result from four
                                     // fights, which will let it stay on a NOP
                                     // then, or some fights and neural nops...
                                     // the whole population will commensally
                                     // stun one another... i hope this helps
                                     // get that under control
                   newskips[destx][desty] += (1);
// don't stun attacker's dna anymore v they like that
//                    newskips[j][i] += 1;          // so defender can sit on a
                                                  // NOP if it wants, stun both
                                                  // instead... winner for longer (only the dna is stunned, not the neural net)
                                                  // on average. actually 'skip'
                                                  // refers to turns not operations                             
                                                  // .. because neural version
                                                  // fights so much it stalls their
                                                  // dna bad so i changed dir+8
                                                  // to dir+1 here and dir+12 for
                                                  // the attacker to 5... so
                                                  // losing a fight in combination
                                                  // with most nops, a poke or
                                                  // a succesfully defended against
                                                  // fight will probably stall but
                                                  // otherwise this should result
                                                  // in less of them and more dna
                                                  // getting run. neuralstun also
                                                  // adds 3 stun so 3*2 + 2 == 
                                                  // makes one, i have two neural
                                                  // subruns so they can stun their
                                                  // own dna twice, stunning twice
                                                  // and losing a fight stalls your
                                                  // dna but they enjoy that in
                                                  // neural version 
                                                  
                    mod -= biteAmount>>1;
                    dnarun_add[destx][desty] += biteAmount>>1; // minimal energy transfer
                                                   // to NOPper to help keep
                                                   // mad energy dynamics
                                                   // among the extra stunning
                  }
                  if (view == 8 && t == drawevery-1) { actions_view[destx][desty] += 2; actions_view[j][i] += 1; }
                }
              }
//    printf("sniff out win crash 5.53\n");                          
              if (actions[1][dir] == 1) { // suck
                tstimuli[destx][desty][1][dir] += 16;
//                printf("suck\n");
                 if ((((soundSource == 7) || (view == 6 || view == 99 && t == drawevery-1))) && !wonafight) { actions_view2[destx][desty] += 1; } // why !wonafight
//                signed int w = (Sint16) dnarun[destx][desty];
                signed int w = (Sint16) grid[destx][desty];
                
		    w -= biteAmount;
if (w >= 0) {                mod += biteAmount;  } else if (w>=0-biteAmount) { mod += ((Sint8) biteAmount)+w+1; } // just 1 free energy from dead or low energy cells, just kill no warming

                // ok quick and unfair transfer stims on a bite
                if(stims[destx][desty] > 9) {
                  if (stims[j][i] <= 246) {
                    stims[destx][desty] -= 9; // fuck it just take a token
                    stims[j][i] += 9;       // and give em 2, create some
                                            // no dont
                  } else { if (stims[destx][desty] > stims[j][i] - 246) {stims[destx][desty] -= stims[j][i] - 246;} else {stims[destx][desty] = 0;} stims[j][i] = 255; }
                }
                if (w < 0 || wonafight) { // kill & breed
                  offspring[j][i][++offspring[j][i][0]] = destx;
                  offspring[j][i][++offspring[j][i][0]] = desty; // for neural version i should
                                              // have 8 offspring destinations
                                              // available per cell... or they
                                              // only get one child per frame
                                              // something for rev 5 with this
                                              // tiled view i want
                  kills += 1;
                } else {  // no kill just bite
                  dnarun_sub[destx][desty] += biteAmount;
                }
                bites += 1;
              } else if (actions[0][dir] == 1) { // give
                tstimuli[destx][desty][0][dir] += 16;
//                printf("give\n");
                dnarun_add[destx][desty] += giveamount;
                mod -= biteAmount;
                gives += 1; 
                if (soundSource == 6 || ((view == 5 || view == 99) && t == drawevery-1)) { actions_view[destx][desty] += 1; }
              } else if (actions[2][dir] == 1) { // poke
                tstimuli[destx][desty][2][dir] += 16;
//                  printf("poke\n");
                  newskips[destx][desty] += dir+12; // in neural versions pokes
                                                   // now add 12+dir stun not
                                                   // 1+dir, and fights add
                                                   // 1+dir not 12+dir, because
                                                   // they fight so much
                  DNA_IP[destx][desty] += (dir+1)<<2;
                  while(DNA_IP[destx][desty] > DNA_Length) { DNA_IP[destx][desty] -= DNA_Length; }
                  pokes += 1;
                  if (soundSource == 8 || ((view == 7 || view == 99) && t == drawevery-1)) { actions_view3[destx][desty] += 1; }
              }
            } // dir loop ends
//    printf("sniff out win crash 5.54\n");            
            if (wantstooutput == 1) { // output
//                    printf("w %i", inputs[j][i]);

//                  if (inputs[j][i] != 0) { // yeah only do this if they have input
                                             // no that sucks sorry
//                    printf("o %i", inputs[j][i]);
//                    fseek(dsp, soundptr,0);

//                    int somechar = data[(rand()/(RAND_MAX>>8))];
                  
                    for (dataloop = 0; dataloop<datalen; dataloop++) {
                      int somechar = data[dataloop];
                      // DNA_IP[j][i] += somechar<<2; // i guess not
                                                      // brain does dna head
                                                      // feed back now
                      // while (DNA_IP[j][i] >= DNA_Length) {DNA_IP[j][i] -= DNA_Length;}

                      if (somechar > 0) {
                        int high = somechar+2;
                        int low;
                        int highest = somechar + 4;
                        int lowest;
                          
                        if (somechar > 1) { low = somechar-2; } else { low = 0; }
                        //low = somechar;
                        if (somechar > 3) { lowest = somechar - 4; } else { lowest = 0; }
                        int reward = 0;

                        if ((Sint16) newcell <= high && (Sint16) newcell >= low) { reward += good_output_reward; goods += 2; } else {reward -= outputpenalty;}
                        if ((Sint16) newcell <= highest && (Sint16) newcell >= lowest) { reward += good_output_reward/3; goods += 1; } else {reward -= outputpenalty/3;}
                        mod += reward;
                      }
                    }
                    inputs[j][i] = 0;
                    outputsctr += 1;
                    //if (newcell > 0) { 
                    outputs[j][i] = newcell; // } // only for vis 
                  // } else {  outputs[j][i] = 0; }
            }
//    printf("sniff out win crash 5.55\n");            
            if (wantstoinput == 1) { // input
                  mod -= inputscost;

                  inputs[j][i] = data[(rand())%datalen]; // signals program will be loaded onto 32 sense
//                  printf("wi %i\n",(unsigned int) inputs[j][i]);
                                              // neurons next turn
                                              // the colour it shows is just
                                              // from the bf data and for fun
//                    DNA_IP[j][i] += inputs[j][i]; // darn
//                    DNA_IP[j][i] += inputs[j][i]<<2; // no
//                    while (DNA_IP[j][i] >= DNA_Length) {DNA_IP[j][i] -= DNA_Length;}
                  progsgot += 1;
                  mod-=inputcost;
            }
		newcell += mod;
		if (newcell < 0) { newcell = 0; } else if (newcell > 255) { newcell = 255;}
            } else { // acts check ends (no-op, vulnerable to poke, harder to fight)
            // how nop with brains
//              printf("nop\n");
//              newskips[j][i] += 7;
              DNA_IP[j][i] += 4*opcodesPerFrame; // neural nop will jmp dna...
              neuralnops += 1;
              while(DNA_IP[j][i] > DNA_Length) { DNA_IP[j][i] -= DNA_Length; }
              if (soundSource == 10 || ((view == 9 || view == 99) && t == drawevery-1)) { actions_view5[j][i] += 3; }
//            }
            // unindented poke skip check ends (no)
            } // acts check ends
//            newcell += (Sint16) ((Sint16) grid[j][i] - (Sint16) dnarun[j][i]);
            if (newcell > 255) { newcell = 255; }
            if (newcell < 0) { newcell = 0; } // ok

//            if (newcell < 0) { newcell == 1; }
            dnarun[j][i] = newcell;
            } else { // if dna_run is off (at brains run)
              //newcell = grid[j][i];
//            newcell *= .97; // no fade
              dnarun[j][i] = newcell;
              
            oldwavepos = wavePos;
            wavePos += curWaveStep; // oops do this outside
            
            soundRewards[j][i]=0;
	    newcell = newcell-128;

            if (newcell > 255) { newcell = 255; }
            if (newcell < 0) { newcell = 0; } // ok

            dnarun[j][i] = newcell;
     
            }
          } else if (run == 2) {  // breed run
//    printf("sniff out win crash 5.6\n");
            if (DNA_on) {

                  if (offspring[j][i][0] > 0)  {
                
                                                 
   Uint8 offsidx;
   for (offsidx = 1; offsidx < offspring[j][i][0]; offsidx += 2) {

                  if (recursive_fair_breed(j, i, offspring[j][i][offsidx], offspring[j][i][offsidx+1], 255, 255, offspring, DNA, Brains, neuroncount, generations, sexctr, newskips, DNA_IP, DNA_DP, dnarun_add, &breeds, &splits, &maxIP, sex_on, 0) > max_breed_fairness) { maxrecursions += 1; }
//                  if (recursive_fair_breed(j, i, offspring[j][i][offsidx], offspring[j][i][offsidx+1], 255, 255, offspring, DNA, Brains, neuroncount, generations, sexctr, skips, DNA_IP, dnarun_add, &breeds, &splits, &maxIP, sex_on, 0) > max_breed_fairness) { maxrecursions += 1; }

                  } // indent this, flamoot
        }
            } else {// DNA_on off
                   } // end breed run
            if (highgen < generations[j][i]) {highgen = generations[j][i];}
            avggen += generations[j][i];
            if (lowgeninpop > generations[j][i]) {lowgeninpop = generations[j][i]; lowgen = generations[j][i];}
          } else { // CA run
            newcell = dnarun[j][i];
            newcell += dnarun_add[j][i];
            newcell -= dnarun_sub[j][i];
            dnarun_add[j][i] = 0;
            dnarun_sub[j][i] = 0;
            skips[j][i] = newskips[j][i];
            Uint8 dir = 0;
            Uint8 op = 0;
            for (op=0;op<4;op++) {
              for (dir=0;dir<8;dir++) {                        
                stimuli[j][i][op][dir] = tstimuli[j][i][op][dir];
              }
            }
            
//            newskips[j][i] = 0;

            if (CA_on) {
            newcell *= 0.99; // fade
if (newcell > 255) { newcell = 255; }            //        newcell += 5; // what is this rule

/*            newcell += 1-(abs((Sint16)(i-y))/(gridrows/7));
            newcell += 1-(abs((Sint16)(j-z))/(gridcols/7));
                
*/
/*            newcell -= dnarun[z+1][y]>>7;
            newcell -= dnarun[z+1][y+1]>>7;
            newcell -= dnarun[z][y]>>7;
            newcell -= dnarun[z][y+1]>>7;

            newcell += dnarun[gridlastx][gridlasty]>>7;
            newcell += dnarun[0][0]>>7;
            newcell += dnarun[0][gridlasty]>>7;
            newcell += dnarun[gridlastx][0]>>7;
                
            newcell += dnarun[gridcolsminusz2][y2]>>7;
            newcell -= dnarun[z2][y2]>>7;
            newcell += dnarun[gridcolsminusz2][gridrowsminusy2]>>7;
            newcell -= dnarun[z2][gridrowsminusy2]>>7;  */

            // wilder if you use modulos not divides. but you can seek homeostasis instead, using the above code if you want
            // ... then the temperature changes in jumps as cell values enter
            // certain ranges... /64 means the granularity is only four, though.
            // newcell should be a float, then it would be better. what i want
            // with the %4 shit below is to get them to carefully tune the
            // values of hotspot neighbourhoods, cooperatively... eventually.
            // best way to hold a temperature is to hold a cell's value still
            // if possible then and if it jumps it should be by 4
            // i can't decide which way is better yet

 //           newcell += 0.5f*(-3)*(abs((Sint16)(i-y))/(gridrows/5));
 //           newcell += 0.5f*(-3)*(abs((Sint16)(j-z))/(gridcols/5));
// ^ five habitable bands, one really cold //

//            newcell += 0.5f*(abs((Sint16)(i-y))/(y2));
//            newcell += 0.5f*(abs((Sint16)(j-z))/(z2));
            // ^ three habitable bands out of a 4x4 grid... and faster math
            // if you modulo these by y2/z2 or some other value rather than
            // divide, you get a diamond grid with hot and coldspots
            // distributed across the neighbourhoods... kind of cool

//            newcell += 0.5f*(abs((Sint16)(i-y))/(y3));
//            newcell += 0.5f*(abs((Sint16)(j-z))/(z3));
            // ^ yet more bands, 8x8 grid, real nice but looks like goatse

            //newcell += 8; // then warming for the corners that always reboot


        //  newcell -= (Uint8)(j*2);

                
/*            newcell -= (Uint8)((dnarun[(z)+1][(y)]>>5)); // far corners
            newcell -= (Uint8)((dnarun[(z)+1][(y)+1]>>5));
            newcell -= (Uint8)((dnarun[(z)][(y)]>>5));
            newcell -= (Uint8)((dnarun[(z)][(y)+1]>>5));

            newcell -= (Uint8)((dnarun[gridlastx][gridlasty]>>5)); // centers
            newcell -= (Uint8)((dnarun[0][0]>>5));
            newcell -= (Uint8)((dnarun[0][gridlasty]>>5));
            newcell -= (Uint8)((dnarun[gridlastx][0]>>5));
                
            newcell -= (Uint8)((dnarun[gridcolsminusz2][y2]>>5));  //middle corners
            newcell -= (Uint8)((dnarun[z2][y2]>>5));
            newcell -= (Uint8)((dnarun[gridcolsminusz2][gridrowsminusy2]>>5));
            newcell -= (Uint8)((dnarun[z2][gridrowsminusy2]>>5)); 
            // end  */


            if (i == 0) { up = gridlasty; } else { up = i-1; }
            if (i == gridlasty) { down = 0; } else { down = i+1; }
            if (j == 0) { left = gridlastx; } else { left = j-1; }
            if (j == gridlastx) { right = 0; } else { right = j+1; }

//            if (dnarun[left][up] < newcell) { newcell--; } else { newcell++; }
//            if (dnarun[left][i] < newcell) { newcell--; } else { newcell++; }
//            if (dnarun[left][down] < newcell) { newcell--; } else { newcell++; }
//            if (dnarun[right][up] < newcell) { newcell--; } else { newcell++; }
//            if (dnarun[right][i] < newcell) { newcell--; } else { newcell++; }
//            if (dnarun[right][down] < newcell) { newcell--; } else { newcell++; }
//            if (dnarun[j][up] < newcell) { newcell--; }       else { newcell++; }  
//            if (dnarun[j][down] < newcell) { newcell--; } else { newcell++; }
// get wind then

            float mod = 6;
            if (dnarun[left][up] < newcell) { mod/=2; } else { mod*=2; }
            if (dnarun[left][i] < newcell) { mod/=2; } else { mod*=2; }
            if (dnarun[left][down] < newcell) { mod/=2; } else { mod*=2; }
            if (dnarun[right][up] < newcell) { mod/=2; } else { mod*=2; }
            if (dnarun[right][i] < newcell) { mod/=2; } else { mod*=2; }
            if (dnarun[right][down] < newcell) { mod/=2; } else { mod*=2; }
            if (dnarun[j][up] < newcell) { mod/=2; }       else { mod*=2; }  
            if (dnarun[j][down] < newcell) { mod/=2; } else { mod*=2; }
            newcell *= mod;
 

Uint8 warmer=0;
Uint8 cooler=0;
Uint8 same=0;

            if (dnarun[left][up] < newcell) { cooler+=1; } else if (dnarun[left][up] > newcell) { warmer+=1; } else { same += 1; }
            if (dnarun[left][i] < newcell) { cooler+=1; } else if (dnarun[left][i] > newcell) { warmer+=1; } else { same += 1; }
            if (dnarun[left][down] < newcell) { cooler+=1; } else if (dnarun[left][down] > newcell) { warmer+=1; } else { same += 1; }

            if (dnarun[right][up] < newcell) { cooler+=1; } else if (dnarun[right][up] > newcell) { warmer+=1; } else { same += 1; }

            if (dnarun[right][i] < newcell) { cooler+=1; } else if (dnarun[right][i] > newcell) { warmer+=1; } else { same += 1; }

            if (dnarun[right][down] < newcell) { cooler+=1; } else if (dnarun[right][down] > newcell) { warmer+=1; } else { same += 1; }

            if (dnarun[j][up] < newcell) { cooler+=1; }       else if (dnarun[j][up] > newcell) { warmer+=1; }   else { same += 1; }

            if (dnarun[j][down] < newcell) { cooler+=1; } else if (dnarun[j][down] > newcell) { warmer+=1; } else { same += 1; }


newcell *= warmer+1; newcell /= cooler+1; newcell *= same+1;

newcell += CA_RULES[warmer][cooler][same];



 
            if (newcell > 255) { newcell = 255; } else if (newcell < 0) {
            // oops but cool
            // newcell = 255;
            newcell = 0; }
            } else {} // if CA off
            tgrid[j][i] = newcell;
          }
        }
      }
    }

//    printf("sniff out win crash 6\n");

    lowgeninpop = highgen; // eh

i = rand()%9;if (i < 8) { j=rand()%(9-i); } else { j = 0; } if (i+j<8) { c=rand()%(9-(i+j)); } else { c = 0; } CA_RULES[i][j][c] = ((Sint8) (rand()%64))-32;


    for (i = 0; i < gridrows; i++) { // do this later now doesnt matter
      for (j = 0; j < gridcols; j++) {
        grid[j][i] = tgrid[j][i];
      }
    }

    if (highgen > highestgen) { highestgen = highgen; }
    avggen = avggen / (float) popsize; // whats wrong with this
    if (oldavggen > 0) {
      avggen = (avggen + oldavggen) /2.0f;
    }
    oldavggen = avggen;
    //if (oldavgSoundReward > 0) {
    //  avgSoundReward = (avgSoundReward + oldavgSoundReward) / (float) cortical_neurons;
    //} // what
    //oldavgSoundReward = avgSoundReward;

    delayctr++;
    if (delayctr == delayevery) {
      printf("Delay 5 seconds in case sounds are backed up or something\n");
      SDL_Delay(5000);
      delayctr = 0;
    }

//    printf("sniff out win crash 7\n");

    t++;

    if (t == drawevery) {
      Uint8 loopview = 255;

      Uint8 oldview = view;
      Uint8 miniGridCols = 6; // mini-grids across
      Uint8 miniGridRows = 3; // mini-grids down

      int minigridcellwidth = ((cellwidth+xspace/2) / miniGridCols); // fine at default
      int minigridcellheight = ((cellheight+yspace) / miniGridRows); // dimensions 
                                     // other sizes you might not want to add xspace
                                    // and yspace, or you might not want to
                                    // subtract 1 from the height, or w/e, uh
      int gridoffX = (screenwidth-((cellwidth+xspace)*gridcols)) / 2;
      int gridoffY = (screenheight-((cellheight+yspace)*(((num_of_neurons/DNA_View_Cell_Size_Divisor)/(gridcols*DNA_View_Cell_Size_Divisor))+1))-((cellheight+yspace)*gridrows)) / 2;
      int minigridxspace = (screenwidth-(minigridcellwidth*gridcols*miniGridCols)) / miniGridCols;
      int minigridyspace = (screenheight-((cellheight+yspace)*(((num_of_neurons/DNA_View_Cell_Size_Divisor)/(gridcols*DNA_View_Cell_Size_Divisor))+1))-(minigridcellheight*gridrows*miniGridRows)) / miniGridRows;
      int minigridoffX = 0;
      int minigridoffY = 0;
      int horMG = 0;
      int vertMG = 0;
      if (view == 99) { loopview = 0; }
      while (loopview == 255 || loopview <= lastview) { // we set loopview 254
                                                       // to stop drawing mini
                                                       // grids, if it starts
                                                       // 0, at lastview
        
      if (loopview < 255) { view = loopview; loopview += 1; }

      if (view == 1) {
        viewdata1 = lowgen;
        viewdata2 = highgen;
        viewdata3 = &generations;
        viewdata4 = 0;
      } else if (view == 2) { viewdata1 = 0; viewdata2 = 255; viewdata3 = 0; viewdata4 = &skips;
      } else if (view == 3) { viewdata1 = 0; viewdata2 = sexoperandpersistance*3; viewdata3 = 0; viewdata4=&sexctr; 
      } else if (view == 4) { viewdata1 = 0; viewdata2 = DNA_Length; viewdata3 = &DNA_IP; viewdata4=0; 
      } else if (view == 5) { viewdata1 = 0; viewdata2 = 8; viewdata4 = &actions_view; viewdata3=0; 
      } else if (view == 6) { viewdata1 = 0; viewdata2 = 8; viewdata4 = &actions_view2; viewdata3=0; 
      } else if (view == 7) { viewdata1 = 0; viewdata2 = 8; viewdata4 = &actions_view3; viewdata3=0; 
      } else if (view == 8) { viewdata1 = 0; viewdata2 = 8; viewdata4 = &actions_view4; viewdata3=0; 
      } else if (view == 9) { viewdata1 = 0; viewdata2 = opcodesPerFrame; viewdata4 = &actions_view5; viewdata3=0; 
      } else if (view == 10) {viewdata1 = cortical_neurons; viewdata2 = num_of_neurons; viewdata3 = 0; viewdata4 = &neuroncount; 
      } else if (view == 11) {viewdata1 = 0; viewdata2 = 127; viewdata3 = 0; viewdata4 = &inputs; 
      } else if (view == 12) {viewdata1 = 0; viewdata2 = 255; viewdata3 = 0; viewdata4 = &outputs; 
      } else if (view == 13) {viewdata1 = 0; viewdata2 = 6; viewdata3 = 0; viewdata4 = &neurskipsandstuns; 
      } else if (view == 14) {
        Uint8 UIsoundRewards[gridcols][gridrows];
        for (j = 0; j<gridcols; j++) {
          for (i = 0; i<gridrows; i++) {
//            if (soundRewards[j][i] < 0) {
//              printf("soundRewards[%i][%i] = %f\n", j, i, soundRewards[j][i]);
//            }
            if (soundRewards[j][i] > 0) {
            UIsoundRewards[j][i] = (unsigned int) (soundRewards[j][i]);
            } else { UIsoundRewards[j][i] = 0; }
//            printf("UIsoundRewards[%i][%i] = %i\nsoundRewards[j][i] = %i\n\n", j, i, UIsoundRewards[j][i], soundRewards[j][i]);
          }
        }
        viewdata1 = 0; viewdata2 = 255; viewdata3 = 0; viewdata4 = &UIsoundRewards; 
      } else if (view == 15) {viewdata1 = 0; viewdata2 = 255; viewdata3 = 0; viewdata4 = &stims; 
      } else if (view == 16) {viewdata1 = 0; viewdata2 = 63; viewdata3 = 0; viewdata4 = &selfmod; 
      } else if (view == 17) {
        int DNA_DP_w_motors[gridcols][gridrows];
        for (j = 0; j<gridcols; j++) {
          for (i = 0; i<gridrows; i++) {
            if (DNA_DP[j][i] > 0) { // wtf it will be
            DNA_DP_w_motors[j][i] = (unsigned int) (DNA_DP[j][i]+((selfmod[j][i]&8)*128) ) ; // the self mod increment/decrement motors add 8 and 8 to selfmod so, do 1 and 2 the same way here if like, you want to see inc and dec ops on the dna dp view too. ok
            if (DNA_DP_w_motors[j][i] < ((selfmod[j][i]&4)*192)) {
              DNA_DP_w_motors[j][i] = 0;
            } else {
              DNA_DP_w_motors[j][i] -= ((selfmod[j][i]&4)*192); // jeez
            }
            } else { DNA_DP_w_motors[j][i] = 0; }
          }
        }



        viewdata1 = 0; viewdata2 = num_of_neurons; viewdata3 = *DNA_DP_w_motors; viewdata4 = 0; 
      } else if (view == 0) { viewdata1 = 0; viewdata2 = 0; viewdata3 = 0; viewdata4=0; }
      if (loopview < 255) {
        drawgrid(screen, Brains, neuroncount[0][0], neuralzeroes, *grid, gridrows, gridcols, minigridcellwidth, minigridcellheight, 0, 0, screenwidth, screenheight, DNA_View_Cell_Size_Divisor, DNA_Length, view, viewdata1, viewdata2, viewdata3, viewdata4, minigridoffX, minigridoffY, 1, 0);
        if (soundSource == view + 1) {  // draw a box around the view in
                                        // multi-view if we're listening
                                        // to it as sound
          drawline(screen, minigridoffX, minigridoffY, minigridoffX, minigridoffY + (minigridcellheight*gridrows)-1, 100, 120);
          drawline(screen, minigridoffX + (minigridcellwidth*gridcols)-1, minigridoffY + (minigridcellheight*gridrows)-1, minigridoffX, minigridoffY + (minigridcellheight*gridrows)-1, 100, 120);
          drawline(screen, minigridoffX, minigridoffY, minigridoffX + (minigridcellwidth*gridcols)-1, minigridoffY, 100, 120);
          drawline(screen, minigridoffX + (minigridcellwidth*gridcols)-1, minigridoffY + (minigridcellheight*gridrows)-1, minigridoffX + (minigridcellwidth*gridcols)-1, minigridoffY, 100, 120);

          drawline(screen, minigridoffX+1, minigridoffY+1, minigridoffX+1, minigridoffY + (minigridcellheight*gridrows)-2, 100, 120);
          drawline(screen, minigridoffX + (minigridcellwidth*gridcols)-2, minigridoffY + (minigridcellheight*gridrows)-2, minigridoffX+1, minigridoffY + (minigridcellheight*gridrows)-2, 100, 120);
          drawline(screen, minigridoffX+1, minigridoffY+1, minigridoffX + (minigridcellwidth*gridcols)-2, minigridoffY+1, 100, 120);
          drawline(screen, minigridoffX + (minigridcellwidth*gridcols)-2, minigridoffY + (minigridcellheight*gridrows)-2, minigridoffX + (minigridcellwidth*gridcols)-2, minigridoffY+1, 100, 120);          

          drawline(screen, minigridoffX+2, minigridoffY+2, minigridoffX+2, minigridoffY + (minigridcellheight*gridrows)-3, 100, 120);
          drawline(screen, minigridoffX + (minigridcellwidth*gridcols)-3, minigridoffY + (minigridcellheight*gridrows)-3, minigridoffX+2, minigridoffY + (minigridcellheight*gridrows)-3, 100, 120);
          drawline(screen, minigridoffX+2, minigridoffY+2, minigridoffX + (minigridcellwidth*gridcols)-3, minigridoffY+2, 100, 120);
          drawline(screen, minigridoffX + (minigridcellwidth*gridcols)-3, minigridoffY + (minigridcellheight*gridrows)-3, minigridoffX + (minigridcellwidth*gridcols)-3, minigridoffY+2, 100, 120);
        }
      } else {
        drawgrid(screen, Brains, neuroncount[0][0], neuralzeroes, *grid, gridrows, gridcols, cellwidth, cellheight, xspace, yspace, screenwidth, screenheight, DNA_View_Cell_Size_Divisor, DNA_Length, view, viewdata1, viewdata2, viewdata3, viewdata4, gridoffX, gridoffY, 1, 0);      
      }
      
//       printf("old minigridoffX = %i\told minigridoffY = %i\thorMG = %i\tvertMG = %i\tminigridcellwidth = %i\tminigridcellheight = %i\tminigridxspace = %i\tminigridyspace = %i\n", minigridoffX, minigridoffY, horMG, vertMG, minigridcellwidth, minigridcellheight, minigridxspace, minigridyspace);
       // debug
      if (horMG < miniGridCols-1) { // wtf
        horMG += 1;
      } else {horMG = 0; vertMG += 1;}
      if (vertMG > miniGridRows) {
        printf("Error: not enough miniGridRows to draw the whole multi-view!\n");
      }
      minigridoffX = (((minigridcellwidth)*gridcols)*horMG)+(minigridxspace*horMG);
      minigridoffY = (((minigridcellheight)*gridrows)*vertMG)+(minigridyspace*vertMG);
      if (loopview > lastview) { loopview = 254; } // thats it
      } // end multiview loop
      view = oldview;
      if (showsynapses & 1)
      {
        if (showsynapses > 3) {
          drawgrid(screen, Brains, neuroncount[0][0], neuralones, *grid, gridrows, gridcols, cellwidth, cellheight, xspace, yspace, screenwidth, screenheight, DNA_View_Cell_Size_Divisor, DNA_Length, view, viewdata1, viewdata2, viewdata3, viewdata4, 0, 0, 0, 1);
        } else {
          drawgrid(screen, Brains, neuroncount[0][0], CellZero_did_fire, *grid, gridrows, gridcols, cellwidth, cellheight, xspace, yspace, screenwidth, screenheight, DNA_View_Cell_Size_Divisor, DNA_Length, view, viewdata1, viewdata2, viewdata3, viewdata4, 0, 0, 0, 1);
        }
      } else {
        drawgrid(screen, Brains, neuroncount[0][0], neuralzeroes, *grid, gridrows, gridcols, cellwidth, cellheight, xspace, yspace, screenwidth, screenheight, DNA_View_Cell_Size_Divisor, DNA_Length, view, viewdata1, viewdata2, viewdata3, viewdata4, 0 , 0, 0, 1);
        // switching to show synapses, three different drawgrids, real nice
      }

      SDL_UpdateRect(screen, 0, 0, screenwidth-1, screenheight-1); // ok drawn

      if (showsynapses == 2) { showsynapses = 3; } else if (showsynapses == 3) { showsynapses = 2; }
      t=0; 

//    printf("sniff out win crash 8\n");

      tt++;
      if (tt == drawsbetweenscoreoutput) {
        int nonplastics = 0;
        int plastics = 0;
        int inhibs = 0;
        int excits = 0;
        int neurons = 0;
        for (i = 0; i < gridrows; i++) {
          for (j = 0; j < gridcols; j++) {
            Uint8 *brainptr = Brains[j][i];
            for (c = 1; c <= neuroncount[j][i]; c++) {
              neurons += 1;
              Uint8 d;
              for (d = 2; d < num_of_synapses; d+=4) {
                if (brainptr[(c*num_of_synapses)+d] == 0) break;
                if (brainptr[(c*num_of_synapses)+d+1]>1) { //printf("%i,%i: synapse at %i of neuron %i is plastic\n",j,i,d,c);
                                                           plastics += 1; } else { nonplastics += 1; } 
                if (brainptr[(c*num_of_synapses)+d+1]&1) { inhibs += 1; } else { excits += 1; } 
              }
            }
          }
        }

    avgSoundReward = avgSoundReward / (float) turnsTaken; // whats wrong with this


        char logbuf[600];
        printf("in world high score %i, highest was %i, lowest is %i, average %f ", highgen, highestgen, lowgen, avggen);
        sprintf(logbuf,"in world high score %i, highest was %i, lowest is %i, average %f\n", highgen, highestgen, lowgen, avggen);
        fputs(logbuf, lf);
        if (soundSource == 1) {printf ("(reward value sound wave,");} else {printf ("(outputs sound wave,");}
        sayview(view);

        printf("hey wow, average of %f soundreward, and %i turns taken\n", avgSoundReward, turnsTaken);
        sprintf(logbuf,"hey wow, average of %f soundreward, and %i turns taken\n", avgSoundReward, turnsTaken);
        fputs(logbuf, lf);
        printf("%i gives, %i pokes, %i skips, %i bites, %i dnanops %i neuralnops %i max recursions %i progs got %i outputs %i good\n%i neurons %i plastic synapses %i non plastic synapses %i excitatory synapses %i inhibitory synapses %i total synapses\n%i lost fights, %i won fights, %i total fights, %i kills, %i breeds, %i splits. max IP %i\n", gives, pokes, skipsctr, bites, nops, neuralnops, maxrecursions, progsgot, outputsctr, goods, neurons, plastics, nonplastics, excits, inhibs, (excits+inhibs), lostfights, wonfights, (lostfights+wonfights), kills, breeds, splits, maxIP);
        char logbuf2[600];
        sprintf(logbuf2, "%i gives, %i pokes, %i skips, %i bites, %i dnanops %i neuralnops %i max recursions %i progs got %i outputs %i good\n%i neurons %i plastic synapses %i non plastic synapses %i excitatory synapses %i inhibitory synapses %i total synapses\n%i lost fights, %i won fights, %i total fights, %i kills, %i breeds, %i splits. max IP %i\n", gives, pokes, skipsctr, bites, nops, neuralnops, maxrecursions, progsgot, outputsctr, goods, neurons, plastics, nonplastics, excits, inhibs, (excits+inhibs), lostfights, wonfights, (lostfights+wonfights), kills, breeds, splits, maxIP);
        fputs(logbuf2, lf);
        char logbuf3[600];
        sprintf(logbuf3, "%i neural skips of dna, %i neural stuns of dna\n", neuralskips, neuralstuns );
        fputs(logbuf3, lf);

        gives = 0; pokes = 0; skipsctr = 0; bites = 0; kills = 0; breeds = 0; splits = 0; maxIP = 0; lostfights = 0; wonfights = 0; nops = 0; maxrecursions = 0; neuralnops = 0; goods = 0; outputsctr = 0; progsgot = 0; neuralskips = 0; neuralstuns = 0;
 //       oldavgSoundReward = 0; 
 oldavggen = 0;
        tt = 0;
	avgSoundReward=0;turnsTaken=0;
      }
    }

//    printf("sniff out win crash 9\n");

    dumplogctr++;
    if (dumplogctr > dumplogevery) {
      dumplogctr = 0;
      fclose(lf);
      usleep(500);
      lf=fopen(logfile,"a");
    }
    
    autosavectr++;
    if (autosavectr == autosaveevery) {
      printf("Autosaving\n");
      savecrit(highgen, DNA_Length, popsize, DNA, Brains, neuroncount, &DNA_IP, &DNA_DP, &generations, "ca-ga.best.dna", "ca-ga.best.brain");
      savecrit(avggen, DNA_Length, popsize, DNA, Brains, neuroncount, &DNA_IP, &DNA_DP, &generations, "ca-ga.average.dna", "ca-ga.average.brain");
      savecrit(lowgen+1, DNA_Length, popsize, DNA, Brains, neuroncount, &DNA_IP, &DNA_DP, &generations, "ca-ga.low.dna", "ca-ga.low.brain");
      // save lowest generation critter too they get generations necrophiling
      autosavectr = 0;
    }

    // ok stims part here wtf

//    printf("sniff out win crash 10\n");
    
    // first lets decay em on every cell
    int stimj; int stimi;
    if (stimdecayctr >= stimdecevry) {
      for (stimj = 0; stimj < gridcols; stimj++) {
        for (stimi = 0; stimi < gridrows; stimi++) {
          Uint8 tem = stims[stimj][stimi];
          if (tem > 1) { stims[stimj][stimi] = (unsigned int) ((float) tem * stimdecay); }
          else if (tem > 0) { stims[stimj][stimi] = 0; }          
        }
      }
      stimdecayctr = 0;
    }
    stimdecayctr++;    

//    printf("sniff out win crash 11\n");
    
    int stimIt = (rand()) % stimchance; // ya
    if (stimIt == 0) {
      stimj = (rand()) % gridcols;
      stimi = (rand()) % gridrows;
//      printf("stimulate %i, %i\n\n", stimj, stimi);
      stims[stimj][stimi] = 255U; // hahaha
                                  // ok so bites should transfer this
      if (stimj < gridlastx) { stims[stimj+1][stimi] = 255U; } // hahaha }
      if (stimj < gridlastx && stimi < gridlasty) { stims[stimj+1][stimi+1] = 255U; } // hahaha }
      if (stimj < gridlastx && stimi > 0) { stims[stimj+1][stimi-1] = 255U; } // hahaha }
      if (stimj > 0 && stimi < gridlasty) { stims[stimj-1][stimi+1] = 255U; } // hahaha }
      if (stimj > 0 && stimi > 0) { stims[stimj-1][stimi-1] = 255U; } // hahaha }
      if (stimj > 0) { stims[stimj-1][stimi] = 255U; } // hahaha }
      if (stimi < gridlasty) { stims[stimj][stimi+1] = 255U; } // hahaha }
      if (stimi > 0) { stims[stimj][stimi-1] = 255U; }
      // good whole neighbourhood
    } 


    
    cycles++;
    if (cycles == exitafter) { return; }

//    printf("sniff out win crash 12\n");
  }

  printf("Quiting SDL.\n");                                      
                                 
  /* Shutdown all subsystems */
  SDL_Quit();
                                         
  printf("Quiting....\n");

  fclose(lf);
  exit(0);
}                                      
