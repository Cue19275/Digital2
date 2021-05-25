var display = {
  zero: function () {
    this.lightsOut();
    $('.A, .B, .C, .D, .E, .F').fadeIn();
  },
  one: function () {
    this.lightsOut();
    $('.B, .C').fadeIn();
  },
  two: function () {
    this.lightsOut();
    $('.A, .B, .D, .E, .G').fadeIn();
  },
  three: function () {
    this.lightsOut();
    $('.A, .B, .C, .D, .G').fadeIn();
  },
  four: function () {
    this.lightsOut();
    $('.B, .C, .F, .G').fadeIn();
  },
  five: function () {
    this.lightsOut();
    $('.A, .C, .D, .F, .G').fadeIn();
  },
  six: function () {
    this.lightsOut();
    $('.A, .C, .D, .E, .F, .G').fadeIn();
  },
  seven: function () {
    this.lightsOut();
    $('.A, .B, .C').fadeIn();
  },
  eight: function () {
    this.lightsOut();
    $('.A, .B, .C, .D, .E, .F, .G').fadeIn();
  },
  nine: function () {
    this.lightsOut();
    $('.A, .B, .C, .D, .F, .G').fadeIn();
  },
  lightsOut: function () {
    $('.A, .B, .C, .D, .E, .G, .D, .F').hide();
  }
};

display.one();
setTimeout(function () {
  display.two();
}, 1000);
setTimeout(function () {
  display.three();
}, 2000);
setTimeout(function () {
  display.four();
}, 3000);
setTimeout(function () {
  display.five();
}, 4000);
setTimeout(function () {
  display.six();
}, 5000);
setTimeout(function () {
  display.seven();
}, 6000);
setTimeout(function () {
  display.eight();
}, 7000);
setTimeout(function () {
  display.nine();
}, 8000);
setTimeout(function () {
  display.zero();
}, 9000);
